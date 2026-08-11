# Helios-Michaelson-Interferometer
Digitally assisted optical platform using a Michaelson Interferometer allowing for magnetostriction testing on laser light. 


A **Michaelson Interferometer** is a typical configuration for interferometry in which a laser first hits a beamsplitter. The light is roughly equally split, travelling in two perpendicular directions, but hit a mirror, which bounces both beams back to the beamsplitter. This makes the light recombine in a strange way, creating a rippling effect and travelling in a completely new direction. The change in light intensity caused by these ripples as one of the mirrors moves can be measured by a photodiode and can be used to calculate the wavelength of the light to, in theory, calculate the phase shift caused by a magnetic field caused by a solenoid. This is done with the formula
$$\lambda = \frac{2d}{\Delta N}$$ , where d is the distance the mirror moves by and ΔN is the number of fringes observed.
In turn, it is therefore possible to measure a **magnetic field**'s strength using the effect on light passing through the system. - see more details in JOURNAL.md for more details on the formulas/methodology used.

# Hardware:

|  |  |
|:-------------|:--------------|
| **Optics** |  |
| Laser Diode | 640-660nm, Recycled from used DVD drive |
| Beam Splitting Glass | Budget 50:50 Cube Beamsplitter|
| Mirrors | 2x λ/10 Flatness Protected Silver Square Mirror, 12.7x12.7mm |
| Lens | 160/0.17 10X Achromatic Objectives Lens |
|**Electronics** | |
| Board | Arduino Uno ATmega328P |
| Amplifier | MCP601-I/P |
| Capacitor | 100 pF Capacitor | 
| Resistor | 100k Ohm 25 Turn Trimmer |
| Coil | Nickel Wire (tentative) |
| Power Supply | DC Variable Power Supply |
|**Mechanical** | |
| Micrometer | 0-13mm Micrometer Flat/Ball Head |
| Adjustment Springs | Recycled from used DVD drive |
| Screws | 10x Assorted M3, M5, M6 Screws w/Nut & Washers |
| Brackets, mounts | 3D Printed from PETG-CF, 2x thin metal rod |
|**Miscellaneous** | |
| Breadboard | Adapted CNC MDF 3040 Spoilboard, 30x36cm |
| Image Surface | Ground Glass (tentative) |

Further explanations are in the JOURNAL.md file - I recommend checking it out! 
