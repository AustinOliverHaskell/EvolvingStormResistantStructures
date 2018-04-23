// Constants/Parameters for simulation
#pragma once

// Simulation Timing
#define SIM_TIME 20

// Rain area
#define HEIGHT 80
#define RANGE  70

// Rain Params
#define WEIGHT 0.10f

#define WIND_SPEED_X  5.0f
#define WIND_SPEED_Y  0.0f
#define WIND_SPEED_Z  0.0f

#define PARTICLE_COUNT 10
#define PARTICLE_SCALING 0.1f

#define PARTICLE_R 0.0f
#define PARTICLE_G 0.0f
#define PARTICLE_B 1.0f

// Fracture Params
#define GLUE_STRENGTH 0.1f
#define RESTING_THRESHOLD 10.0f

// Fracture Body / Structure Params
#define SEGMENT_MASS 1.0f
#define SCALING 5.0f

// For future use
//#define CUBE_STRUCTURE
//#define TETRA_STRUCTURE

// Geometry Constants
#define FACES_PER_SEGMENT 4
#define TRIANGLE_SIZE 3