# MSPM0G3507 循迹瞄准小车下位机

这是一个团队协作完成的小车项目。本仓库重点展示我负责的 **MSPM0G3507 下位机电控部分**，包括双电机驱动、编码器测速、速度闭环、按键输入和基础定时工具。循迹、瞄准或整车其他模块可能由团队其他成员协作完成；这里不将团队整体成果表述为个人独立完成。

## 工程环境

代码以 Texas Instruments MSPM0G3507 为目标芯片，目录中保存了多个 Code Composer Studio（CCS）工程与外设实验。工程包含 `.project`、`.cproject`、SysConfig (`.syscfg`) 配置及 `targetConfigs` 调试配置，可在安装相应 MSPM0 SDK 和 SysConfig 组件的 CCS 环境中导入。

仓库里的 `Debug`、`Release` 和 clangd 索引属于本地生成内容，不是源代码。根目录 `.gitignore` 会排除这些文件；编译时应由本机工具链重新生成。

## 核心控制链路

推荐从 `DS2025/pid` 阅读当前最完整的一组下位机控制代码：

1. **编码器 GPIO 中断**：`Hardware/encoder.c` 的 GPIO 中断服务程序读取两路正交编码器 A/B 相，根据相位关系累加或递减左右电机计数。
2. **转速换算**：周期采样后，`Calculate_Motor_RPM()` 根据编码器计数、采样时间、每转脉冲数和减速比换算输出轴 RPM。
3. **双电机增量式速度 PI**：`Hardware/motor.c` 为 A、B 两个电机分别保存误差历史，根据目标速度与当前速度计算 PWM 增量，并对输出限幅。
4. **方向与 PWM 驱动**：`Set_PWM()` 根据 PWM 正负切换两组方向 GPIO，再向两个定时器比较通道写入占空值，实现双电机正反转和调速。
5. **周期调度**：`empty.c` 在定时器中断中执行按键读取、编码器计数采样、RPM 计算、PI 更新和 PWM 输出。

这条链路形成“编码器脉冲 → RPM → 速度误差 → 增量式速度 PI → 方向 GPIO / PWM”的闭环。代码中的采样周期、编码器参数、减速比、PI 参数和 PWM 限幅均应按实际电机与底盘重新测定。

## 辅助模块

- `Hardware/key.c` / `key.h`：按键扫描以及单击、双击、长按等输入判断，供运行/停止等状态控制使用。
- `Hardware/board.c` / `board.h`：SysTick 初始化、毫秒/微秒延时和串口打印重定向等基础工具。
- `empty.syscfg`：GPIO、定时器、PWM、串口等外设的 SysConfig 配置入口。
- 其他 CCS 示例目录：保留编码器 GPIO 中断、输入捕获、PWM、周期定时器和电机驱动等分阶段验证工程，便于追溯开发过程。

## 推荐阅读顺序

1. `DS2025/pid/Hardware/motor.c` 与 `motor.h`：理解方向控制、PWM 输出和两路增量式速度 PI。
2. `DS2025/pid/Hardware/encoder.c` 与 `encoder.h`：理解正交编码器中断计数和 RPM 换算。
3. `DS2025/pid/empty.c`：结合定时中断观察闭环调度；该历史文件的部分中文注释存在编码遗留，阅读时应以可辨识代码逻辑为准。
4. `DS2025/pid/Hardware/key.c`、`board.c` 及对应头文件：了解输入状态和时间基础设施。
5. `empty.syscfg`、`.project` 与 `.cproject`：核对具体工程的引脚、外设实例和 CCS 构建设置。

`DS2025/pid` 和 `DS2025/pid2` 是开发过程中的快照，可能存在参数、配置或实验状态差异；建议以源码和各自 SysConfig 配置为准进行对照，不应把目录名理解为正式版本号或性能等级。部分历史快照的注释存在编码遗留，由于原始字符编码不明，本仓库暂未对其进行猜测性改写。

另需注意，`DS2025/pid/Hardware/encoder.c` 的历史注释与代码常量并不一致：注释描述的倍频系数和减速比，与 `MULTIPLY_FACTOR`、`GEAR_RATIO` 的实际取值存在差异。仅凭现有快照无法判断注释或常量哪一方正确，必须结合实车编码器规格、信号沿配置、接线方式和实际转速测量复核后再确定。

## 复现与调试提示

- 在 CCS 中导入目标工程，确认 MSPM0 SDK、编译器与 SysConfig 版本可用。
- 先断开电机负载或架空车轮，核对编码器计数正负方向和 H 桥方向引脚。
- 使用固定采样周期验证 RPM 换算，再逐步调整速度 PI；避免未经验证直接使用现有参数驱动不同电机。
- 检查 PWM 上限、电源能力、急停/停机逻辑和机械安全后，再进行落地测试。

本仓库记录的是下位机控制实现与开发快照，不在此声明瞄准精度、循迹性能或比赛成绩。

## English summary

This team project targets an MSPM0G3507-based mobile robot. This repository highlights my contribution to the **low-level controller**, including quadrature encoder counting through GPIO interrupts, RPM calculation, direction GPIO and PWM motor drive, independent incremental speed PI loops for two motors, button handling, and SysTick-based timing utilities.

The CCS workspace contains several peripheral experiments and development snapshots. Start with `DS2025/pid/Hardware/motor.c`, `DS2025/pid/Hardware/encoder.c`, and their headers, then use `DS2025/pid/empty.c` to follow the periodic control flow. Some historical comments have legacy encoding damage and were not rewritten speculatively because their original character encoding is unknown. The encoder comments also disagree with the multiplication-factor and gear-ratio constants; the repository alone cannot establish which values are correct, so they must be checked against the physical encoder, wiring, edge configuration, and measured speed. The `pid` and `pid2` directories should be treated as development snapshots rather than performance-qualified releases. Motor, encoder, sampling, PI, and PWM parameters must be validated on the actual vehicle.
