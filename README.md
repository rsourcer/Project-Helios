# Helios-Michaelson-Interferometer
Digitally assisted optical platform using a Michaelson Interferometer allowing for magnetostriction testing on laser light. 


A **Michaelson Interferometer** is a typical configuration for interferometry in which a laser first hits a beamsplitter. The light is roughly equally split, travelling in two perpendicular directions, but hit a mirror, which bounces both beams back to the beamsplitter. This makes the light recombine in a strange way, creating a rippling effect and travelling in a completely new direction. The change in light intensity caused by these ripples as one of the mirrors moves can be measured by a photodiode and can be used to calculate the wavelength of the light to, in theory, calculate the phase shift caused by a magnetic field caused by a solenoid. This is done with the formula
$$\lambda = \frac{2d}{\Delta N}$$ , where d is the distance the mirror moves by and ΔN is the number of fringes observed.
In turn, it is therefore possible to measure a **magnetostriction** strength using a mirror attached to a metal rod inside a solenoid - as the magnetic field affects the rod, the mirror moves, and the fringes shift in a measurable manner. - see more details in JOURNAL.md for more details on the formulas/methodology used.
<div align="left">
  <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-Interference%20pattern%20example.jpg" width="400" />
</div>
Fig 1.01: Example of an enlarged fringe image produced by a michaelson interferometer. (Wikipedia Commons) [1]


# Hardware:

|  |  |
|:-------------|:--------------|
| **Optics** |  |
| Laser Diode | Budget 650nm Laser|
| Beam Splitting Glass | Budget 50:50 Cube Beamsplitter|
| Mirrors | 2x λ/10 Flatness Protected Silver, Ø1/2" Mirror |
| Lens | 160/0.17 10X Achromatic Objectives Lens |
|**Electronics** | |
| Board | Arduino Uno ATmega328P |
| Amplifier | MCP601-I/P |
| Capacitor | 100 pF Capacitor | 
| Photodiode | BPW34 |
| Resistors | 100kΩ 25 Turn Trimmer + 100Ω Fixed Resistor|
| Rod | Nickel Rod |
| Solenoid | Made from Copper Wire |
| Power Supply | DC Variable Power Supply |
|**Mechanical** | |
| Micrometer | 0-13mm Micrometer Flat/Ball Head |
| Screws | 10x Assorted M3, M5, M6 Screws w/Nut & Washers, Heat Insert set |
| Brackets, mounts | 3D Printed from PETG-CF |
|**Miscellaneous** | |
| Breadboard | Adapted CNC MDF 3040 Spoilboard, 30x36cm |
| Image Surface | Grid Paper |

# Acronym List:

This is a reference to understand every acronym used

Optical\
BS: Beamsplitter\
M1: Mirror 1 (Micrometer mirror)\
M2: Mirror 2 (Solenoid mirror)\
PD: Photodiode\
Electronics\
PS: Power Supply\
NR: Nickel Rod\
S or SLD: Solenoid\
AMP/TIA: Trans-Impendence Amplifier\
Mounts BSM: Beamsplitter mount\
LDM: Laser diode mounting bracket\
LMB: Lens mounting bracket\
SMM: Solenoid mirror mount\
MMM: Micrometer mirror mount\
PMB: Photodiode mounting bracket\
SPB: Spoilboard\

**3D Printing**
- To print all components, the stl files were used and sliced into gcode- this may lead to inconsistencies when using the step file! Please beware of this if trying to replicate the experiment.

# Testing Checklist

**Preparation**

1: Prepare a clean, flat surface to work on.\
2: Use a vacuum cleaner on work surface and isolate ventilation of room to ensure no dust enters. Ideally, use an air purifier to mitigate dust further.\
3: Connect ATMega32P to power.\
4: Wear disposable gloves to ensure touched components remain dust free.\
5: Gently take out the beam splitter out of container, while holding its edges. Avoid contact with flat surface.\
6: Place the beam splitter flat onto the BSM mount.\
7: Gently take out the mirror while holding its circular edge - a plier may be used to facilitate removal from the case and precise insertion.\
8: Place the mirror onto the MMM mirror mount whilst avoiding contact between the plastic mount and the silvered surface.\
9: Repeat steps 7-8, but place the mirror onto the SMB mirror mount instead.\

**Calibration**

1: Using the spoilboard ruler markings, ensure L1 (distance from mirror 1 to beamsplitter) is within a millimeter's difference from L2 (distance from mirror 2 to beamsplitter) and that the micrometer is not fully extended.\
2: Use piece of cut paper to determine where laser images are at key points (beside the laser origin and in front of the lens)\
3: Align accordingly using screw mounts until all images land at the same place (on the beam)\
4: If needed, adjust lens position precisely using translation screws until the recombined beam is at the lens center.\
5: If needed, adjust laser focal length with focal adjustment guide until the beam does not visibly diverge or converge at a point, using the lens image and cut paper to measure laser size.

Further explanations are in the JOURNAL.md file - I recommend checking it out! 

# Electronics
  <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-%20Tinkercad%20wiring%20schematic.png" width="400" />


Sources for this document:\
[1]

[Interference pattern Michelson Interferometer](https://commons.wikimedia.org/wiki/File:Interference_pattern.jpg) by Cecilia.p under Creative Commons Attribute 3.0 Unported
