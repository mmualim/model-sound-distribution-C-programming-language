**Project Overview**

This project is a C program that designed and implemented a program that models the sound patterns (sound distribution) in an area with multiple loudspeakers, calculating and mapping sound levels across specified observation points.

**Stages**

 1. Reading Loudspeaker Data

- Reads x, y coordinates and sound levels of loudspeakers, storing them in a structured array.
- Calculates the combined sound level at the origin (0,0) using the sound contributions from each loudspeaker.

2. Observation Points

- Reads multiple observation points and computes the sound level at each, considering all loudspeakers' contributions.
- Outputs sound levels at these specific coordinates.

3. Grid-Based Sound Analysis

- Analyzes sound levels across a grid within a 312 x 312-meter area.
- Counts and reports grid points where sound levels fall below 55 dB, identifying areas with insufficient sound coverage.

4. Sound Map Visualization

- Creates a visual "sound map" of the area with characters representing different sound levels.
- Maps sound contours using a grid, where characters indicate various dB ranges across the area.

Each stage builds upon previous steps, from basic data handling to complex spatial sound mapping.

Score 19/20
