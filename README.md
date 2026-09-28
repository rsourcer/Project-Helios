# Helios-Michaelson-Interferometer
Digitally assisted optical platform using a Michaelson Interferometer allowing for magnetostriction testing using red laser light. 


A **Michaelson Interferometer** is a typical configuration for interferometry in which a laser first hits a beamsplitter. The light is roughly equally split, travelling in two perpendicular directions, but hit a mirror, which bounces both beams back to the beamsplitter. This makes the light recombine in a strange way, creating a rippling effect and travelling in a completely new direction. The change in light intensity caused by these ripples as one of the mirrors moves can be measured by a photodiode and can be used to calculate the wavelength of the light to, in theory, calculate the phase shift caused by a magnetic field caused by a solenoid. This is done with the formula
$$\lambda = \frac{2d}{\Delta N}$$ , where d is the distance the mirror moves by and ΔN is the number of fringes observed.
In turn, it is therefore possible to measure a **magnetostriction** strength using a mirror attached to a metal rod inside a solenoid - as the magnetic field affects the rod, the mirror moves, and the fringes shift in a measurable manner.
<div align="left">
  <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-Interference%20pattern%20example.jpg" width="400" />
</div>
Fig 1.01: Example of an enlarged fringe image produced by a michaelson interferometer. (Wikipedia Commons) [1]


The aim of this project is therefore to detect fringe shifts caused magnetostrictive strain. The object's technical objective is to build a Michaelson Interferometer system which can:
- Takes a laser diode's output
- Splits the light through a beam splitter component
- Recombine light with the help of two mirrors, creating the interferometric patterns crucial to the experiment
- Project the image onto a photodiode or expand it with a lens
- Detect interference patterns using a TIA photodiode system as one of the mirrors moves parallel to the laser light.
- Detect magnetostriction through fringe movements spotted by the photodiode's signal output\
See JOURNAL.md for further constraints and objectives.



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
SPB: Spoilboard

# 3D Models
- To print all components, the stl files were used and sliced into gcode- this may lead to inconsistencies when using the step file! Please beware of this if trying to replicate the experiment.

# Testing Checklist

**Preparation**
---
1: Prepare a clean, flat surface to work on.\
2: Use a vacuum cleaner on work surface and isolate ventilation of room to ensure no dust enters. Ideally, use an air purifier to mitigate dust further.\
3: Wear disposable gloves to ensure touched components remain dust free.\
4: Gently take out the beam splitter out of container, while holding its edges. Avoid contact with flat surface.\
5: Place the beam splitter flat onto the BSM mount.\
6: Gently take out the mirror while holding its circular edge - a plier may be used to facilitate removal from the case and precise insertion.\
7: Place the mirror onto the MMM mirror mount whilst avoiding contact between the plastic mount and the silvered surface.\
8: Repeat steps 7-8, but place the mirror onto the SMB mirror mount instead.\

**Calibration**
---
1: Connect ATMega32P to power.\
2: Using the spoilboard ruler markings, ensure L1 (distance from mirror 1 to beamsplitter) is within a millimeter's difference from L2 (distance from mirror 2 to beamsplitter) and that the micrometer is not fully extended.\
3: Use piece of cut paper to determine where laser images are at key points (beside the laser origin and in front of the lens)\
4: Align accordingly using screw mounts until all images land at the same place (on the beam)\
5: If needed, adjust lens position precisely using translation screws until the recombined beam is at the lens center.\
6: If needed, adjust laser focal length with focal adjustment guide until the beam does not visibly diverge or converge at a point, using the lens image and cut paper to measure laser size.

**Electronic Measurement**
---
1: If unconnected, connect the Photodiode anode to the 5V AtMega32P pin.\
2: Connect the GND wire from the op-amp's Pin 3 to the GND AtMega32P pin.\
3: Power on the AtMega32P and turn on the power supply.\
4: Precisely move mirror 1 using the permitted movement in the MMM until the signal modulation drops significantly on screen, making sure that the laser dot image hits the photodiode - this ensures the photodiode is measuring dips produced by Michaelson fringes!\
5: Gradually set power supply current to 10A in about 5 seconds. Be sure to remain as constant as possible.\
6:Observe change produced in photodiode signal.\
Further explanations are in the JOURNAL.md file - I recommend checking it out! 

# Electronics
  <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-%20Tinkercad%20wiring%20schematic%2001.png" width="500" />
  Fig 1.02: Original theoretical wiring for TIA amplification system for a photodiode.
 <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-%20Tinkercad%20wiring%20schematic%2002.png" width="500" />
  Fig 1.03: Real-world wiring for TIA amplification system used in trial results.

There are two electronic circuits which make up the interferometry platform. The first is pictured above - it passes 5V through an MCP601 op-amp paired with a BPW34 photodiode to receive and amplify light signals, connected to the microcontroller - also connected to the 3.3V power source is 100Ohm resistor in series with a 650nm red laser diode.

The second is a 10A,30V rated power supply in CC mode running through a 120 turn, 25ft copper wire to create a solenoid magnetic field, which is used to measure magnetostriction inside a nickel rod:\
 <img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-%20Solenoid%20wiring%20representation.png" width="500" />\
  Fig 1.04: Electrical wiring diagram of DC power supply with solenoid.
  
# Results
Following the Electronic Measurement protocol:
- A significant and repeated drop in signal strength of about 1.0(+-0.5) has been observed when the power supply current is increased at a steady rate.
- When the current is increased to 10A very quickly, the signal strength drops instantaneously.
- When the photodiode is fully covered, increasing the current does not affect it in any way.
Due to these factors, qualitative proof of the magnetostrictive properties of a nickel rod has been established beyond reasonable doubt, as the phase shift must can only have been caused by mechanical movement.
<img src="https://github.com/rsourcer/Project-Helios/blob/main/src/Images/Helios%20-%20Magnetostriction%20test%2001.jpeg"/>


Sources for this document:\
[1]

[Interference pattern Michelson Interferometer](https://commons.wikimedia.org/wiki/File:Interference_pattern.jpg) by Cecilia.p under Creative Commons Attribute 3.0 Unported
