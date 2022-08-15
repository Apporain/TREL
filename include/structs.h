#ifndef TREL_STRUCTS_H
#define TREL_STRUCTS_H

#include "DLLDefines.h"

// Comp area calculations
typedef struct {
    float avg_long_area, avg_trans_area, avg_burn_area, burn_std_deviation, burn_sum_diff;
} TREL_EXPORT comp_area_t;

// Propellent grains structure
typedef struct {
    unsigned int amount;
    float init_inter_radius, extern_radius, longitude, grain_separation;
} TREL_EXPORT grains_t;

/* Fuel structure */
typedef struct {
    float const_burn_rate, pressure_exponent, density, burn_rate;
} TREL_EXPORT fuel_t;

// Estructura para tuberia
typedef struct tubing
{
   char *material;
   float diameter_ext, wall_thickness, internal_radius;
   float young_module, sector_angle, mean_tubing_diameter;
   float shear_stress_tension, shear_stress_pressure;
   float ult_stress_tension, ult_stress_pressure;
   float transversal_area, material_area;
} TREL_EXPORT tubing_t;

// Estructura para tornillos
typedef struct screws
{
	float diameter, dist_center_wall;
	unsigned int amount;
    float area_per_screw, screw_occupied_area;
	char  *material;
    float width_cutting_segment;
} TREL_EXPORT screws_t;

// Estructura del engine
typedef struct engine
{
	float pressure;                // chamber pressure in psi
	float escape_vel, temperature;
    float width_condition, margin_of_safety, max_stress, radial_stress;
    float tangencial_stress, longitudinal_stress, max_pressure;
    grains_t *grains;              // ptr to intialized struct
    fuel_t *fuel;
    tubing_t *tube;                // ptr to intialized struct
	screws_t *screws;              // ptr to initialized struct
    comp_area_t* comp_area_values; // ptr to initialized struct
} TREL_EXPORT engine_t;

#endif //TREL_STRUCTS_H
