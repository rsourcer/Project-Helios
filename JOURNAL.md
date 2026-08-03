# **Engineering Log for Open Source Michaelson Interferometer**
**Revision 0.1**
Raoul Salemi
This log is accurate as of 02/08/2026, 23:26 PM EST

This document is to keep track of and formulate daily ideas along the course of this project. This will include any research, objectives, constraints and thoughts.

# **About this project**

The object's technical objective is to build a Michaelson Interferometer system which can:
- Takes a laser diode's output
- Splits the light through a beam splitter component
- Recombines it with the help of two mirrors, creating the interferometric patterns crucial to the experiment
- Expands the image onto a photodiode using a lens
- Detects interference patterns using a moving TIA photodiode system.
It can then:
- Accurately calculate wavelengths (defined later) based off photodiode's movement along the micrometer's translation.
- Determine magnetostriction constant of a solenoid on which a mirror is mounted, based off the change in position of the aforementioned mirror.

**The formula for measuring wavelength as the photodiode moves is**
$$\lambda = 2d$$ 

However, Michaelson Interferometers also prove very useful for a variety of experiments, one of such being magnetostriction. While the photodiode now stays static, this studies the change of distance in the mirror facing the photodiode once mounted to the edge of a ferromagnetic sample rod. As a magnetic field is contained inside it, the rod can either expand or contract, changing the mirror's position. We can therefore measure its magnetostriction constant by first, finding out how much the change in size of the coil through the movement of the mirror, with the formula:

$$\Delta L = N_{fringes} \cdot \frac{\lambda}{2} $$
Where N_{fringes} is the amount of peaks seen in the photodiode signal and λ is the laser wavelength. Then, use 
$$\lambda_m = \frac{\Delta L}{L_0}$$
Where L0 is the length of the unmagnetized rod, and λm is the magnetostriction strain. Then, to find the field strength of the rod, H, we can use 
$$H = \frac{N \cdot I}{l}$$
Where N is the number of turns in the coil, I is the current, and L is the length of the coil.
Then, increasing H (by raising the current) until dL plateaus and reaches a stable value. At that point, λm will be equal to the magnetostriction constant for the metal, λs.


The optical phase shift of the light can also be calculated, and varies by 
$$\Delta \phi = \frac{4\pi \Delta L}{\lambda}$$
[1]
# **Components needed**

*Optical:*
- Laser Diode 
	The laser diode is what provides the system with an initial, focalized and uniform light source, crucial for the interferometry experiment as its intensity will be measured. It will be recycled from the DVD drive.
- Beam Splitting Glass (Cube/Flat)
	This component splits the rays of light emitted by the laser light and sends them towards the parallel and perpendicular mirrors when at a 45 degree angle respective to the laser diode. It is important that this part splits the light evenly, as uneven distribution could alter results.
- 2x Reflective Flat Mirror
	The mirrors reflect the light back to be recombined towards the beam splitter, which is what causes the interference effect - light acting on itself at the same place, cancelling itself out. λ/4 optical precision or higher would be wanted for such mirrors to ensure their accuracy for interferometry, while keeping them at a reasonable price point.

- Optional: Compensating glass plate
	In multi-wavelength light applications, this is crucial for accuracy, and makes sure that light of all wavelengths travel through the same amount of glass no matter where the beam splitter sends them. Without it, with multiple wavelengths, refraction effects make the light much less useful for experimentation.

*Mechanical:*
- Mirror adjustment system (M3 screws, plates)
	This is to adjust where the mirrors are on the system, fixing them in place yet allowing 1 axis of translational movement. One of the mirrors should also be connected to the solenoid circuit for magnetostriction testing.
- Micrometer photodiode system (for moving photodiode to measure wavelength)
	This is to very precisely adjust the distance along which the photodiode will move: as the photodiode moves further into and out of the ray, the light intensity will vary due to the fringes cancelling out in different locations, thus producing a clear electrical signal. This signal is what will be used to calculate the wavelength of the light, depending on how far the photodiode moves - therefore, high precision for its movement is important. It should also be able to lock into fixed position when the coil's magnetism is being tested.
- Metal Breadboard
	This will be a solid starting plate to place all our components on, and fix them in place where they are desired.

*Measurement/Calibration:*
- Divergent Lens (Concave)
	This enlarges the image of the interference fringes, allowing for calibration and visual testing (to make sure no unusual behaviour is produced). Short focal lengths preferred as the image should be enlarged quite a bit.
- Ground glass (any surface producing clean fringe image)
	This is a surface to show the clear interference pattern enlarged by the lens.

*Electronics:*
- Photodiode sensor
	This component picks up the recombined light emitted by the laser and sends electrical pulses based on the light's intensity.
- Amplifier
	Amplifies the photodiode's detection of the laser, filtering out all other muddying noise.
- Arduino Uno (or alternative)
	Processes the signal from photodiode, allowing the data to be analyzed from a computer.
- Coil
	During magnetostriction tests, a mirror is mounted onto it, and the wire expands/contracts as a magnetic field flows through it.

*Software:*
- KiCad (for electronics schematics (?))
- TinkerCAD (for visual representation)
- Python (programming of electronics (?))
- any 3d printing software (I have experience in Blender and Fusion 360)

# **Constraints** 

- BUDGET: 350 CAD
	The project must be a relatively low-cost solution. Professional interferometry equipment can be very expensive - at the time of writing, according to the website Edmunds, the cheapest available cube beam splitter alone, is 389 CAD, [2]. These beam splitters are considered rather standard for professional Michaelson optics projects. Using such optical grade components, it is highly unrealistic to build the interferometry platform within this budget range. It is to note that cheaper types of beam splitters do exist, and this budget will incentivize innovative usages for components.

- Recycled components
	While doing preliminary research in DIY interferometry, it struck my eye that many projects use recycled components to achieve their goals with relatively much power cost, while still retaining rather high precision. (3 Project Examples) Within that context, this project, too, must make creative use and source components from at least one recycled item - a component for which the intention of procurement was not originally interferometry or any other optical experimentation.
- Magnetostriction element
	The platform must be able to perform magnetostrictive tests on a solenoid, and determine its magnetostriction constant. This is the end goal of the interferometer, as it shows a real world application in which it can be used, beyond determining the wavelength of the laser diode. Doing so, it must also pass the precision aspect of the project.

- 3D Printing aspect
	To build a Michaelson interferometer, precise adjustment of distances is needed. Therefore, it would be reasonable to use my 3D printer, to this end. An important secondary goal of mine would be to test structural elements of pieces printed for this project from varying infill percentages and patterns, extrusion settings- etc, to make the most optimal 3D printed components for the interferometer. What defines "most optimal 3D printed components" will be defined later. My goal for this constraint is to further my knowledge of materials testing. 

- Precision aspect
	It would be futile to build an interferometer if it is not able to, well, interfere. Therefore, the uncertainty of the device's frequency measurements, once calculated (with electronic measurement technique - photodiode moving along the laser's fringe patterns) must not be over +-10% in nanometers. For a given 650 nm light source, this means that the uncertainly should not be +-6.5 nm. There should be ≈10kHz bandwith in the TIA circuit. During magnetostriction, λs should be calculated within a 10% margin of the expected value.

- Time aspect
	Given that the Stardance Hack Club project is ending on September 31st, it would be reasonable to finish this project by September 1st, 2026, as to not overlap with scholarly life. (to be removed?)

# **Assumptions**

	Laser wavelength ≈650 nm 
	Ambient temperature ≈20°C 
	System assembled indoors
	PETG sufficiently stiff for preliminary testing
	

# **Daily progress tracking**


	2026-07-23
	Goal: Gain a concrete understanding of what I need for this project
	Time spent: 48 min
	Activities: Research, journaling (creation of this document, checking product listings
	
	Decisions:  
	 D-001 - I have opted to use an unused DVD drive to source many of the components for a Michaelson Interferometer
	 
	Reason: This seems to be a common element of low cost solutions for this device: DVD drives come with laser diodes (640-660nm) , lenses and a semi transparent mirror, parts which have already been tested as useful for the creation of a Michaelson Interferometer in the past. [3]
	


Lingering Questions: What is the purpose of the compensator mirror? Why do some interferometer systems not use it? What precisional advantage could it offer?
Retroactive answer: The compensator mirror is used in multi-wavelength applications where the light must refract through the same amount of glass no matter where the beam splitter hits to obtain an accurate recombined image. Therefore, this glass serves to compensate for the side which bounces off the beam splitter initially. IT does not offer a precisional advantage in single wavelength applications. 

--------------------------------------------------------------------------

	2026-07-24
	Goal: Better my mental picture of the required assembly
	Time spent: 
	Activities: Setting up KiCad, sketching rough paper blueprint, researching required electronic components
	
	Decisions:  
	 D-002 - I have opted to have two variations of the system - one to calibrate the interferometer, consisting of a lens and a surface where the fringes will be visible - and one consisting of the electronic measuring components. This is to maximize the ease of precise set-up and reliable measurement precision of the respective methods.
	 
	D-003 - I have opted to use an Arduino Uno R3 compatible clone rather than the official product to save cost. The Elegoo R3 is currently the most seemingly promising option. This will allow to maximize value elsewhere.
	


Lingering Questions: Why must we need a capacitor and resistor for the circuit? How will using or not using an amplifier play into the measurement system?
Answer: When a photodiode receives light, it does not modify the voltage of the circuit in of itself, but the amount of current flowing through it. This is what allows us to get a signal. However, without an amplifier, the difference in current produced by the light can be minimal and prone to noise, greatly decreasing its efficiency. Therefore, the amplifier helps to mitigate the effects caused by noise, and get a much clearer picture of the laser's signal.

--------------------------------------------------------------------------
2026-07-26
	Goal: Completely understand electronics aspects of the interferometry
	Time spent: 
	Activities: Research on electronics equipment needed. Beginning a rough KiCad schematic.
	
	Decisions:  
	 D-004 - I have decided on what parts I will use - I will couple the Elegoo R3 as discussed yesterday with a BPW43 photodiode, as it is a photodiode suited for near-IR range, inexpensive and has lots of educational resources available. Coupled to these two components could be a UA741 op-amp, which seems to be a common pairing with this photodiode.[4]
	
One thing which helped me today was the BPW43 photodiode tutorial [5], which helped me to further understand how the electronics of this project will function. 

Lingering Questions: Given my needed applications, should I really use KiCad? Should I create a PCB, or invest in a breadboard? What advantages and disadvantages would there be to this? Is this still a question for which it is too early to tell?
Answer: ...No. There is no real benefit to remodel the circuit on KiCad as TinkerCAD already has a schematic model which works fine. For the photodiode system, the PCB may pose a disadvantage given there would be 2-3 components on it, one of which would have to move along an axis of translation which would be made much harder. 


-------------------------------------------------------------------------------------------------------------
2027-07-27
	Goal: Finalize real electronic design and schematic
	Time spent:
	Activities: Journal refining, Researching TinkerCAD to further progress on electronics for my project
	
	Decisions:  
	 D-005 - I decided to use TinkerCAD to create a model of the TIA photodiode circuit, as many templates are available to choose from - this will make it easy for me to verify my circuit logic. It also has a much smaller learning curve than KiCad does.
	
One thing which helped me today was the TinkerCAD photodiode preset, which shows how to make a (albeit less complicated) version of the photodiode system I seek to create. Using this, I can easily gain a clearer picture of what the electronics are supposed to look like once adapting it into a TIA design, as opposed to immediately jumping into KiCad and hoping to understand - what I felt I was doing in the previous days of research. This also allows me to pre-emptively program the circuit long before getting around to building it. (and, of course, the analog photodiode stuff is not included in TinkerCAD, so I can only use the code blocks offered as simple guidance). My course of action is now to use the simplified TinkerCAD model to understand the wiring, then, replicate it on KiCad now that I have improved my knowledge on how to use the program.


------------------------------------
2027-07-28
	Goal: ACTUALLY finalize electronic design. Yesterday, I ran into a problem with the circuit which rather confused me. Today, I want to focus on getting this template TIA circuit running properly, as to understand what is going on.
	Time spent:
	Activities: Rewiring TinkerCAD Circuit, debugging said circuit.
	
	 Decisions:
		 D-006: I am reconsidering the usage of the UA741 op-amp, as it seems to be an unfit match for the current application. The supply is 5V, meaning that it falls on the short end of its rated voltage range (~4.5-40V) [6] While it could still be viable, other op-amps such as the OPA381 could be more effective for the task at hand. This would translate into real world implications for bettering our precision and accuracy results when testing our interferometer.
	
	
I ran into many problems while debugging the TinkerCAD circuit to be operational. I based myself off a pre-existing default photodiode circuit template (credit to Tom Igor for the C++ code) and had to retrofit it into the TIA circuit system I will use. However, the amplifier proved to be very tricky to wire. Using my online resources, I had been able to get it in a way as to work in reducing the measured signal, which made the variance in intensity go from about 203 (from 10-213) to only 1 (from 512-513). I spent hours reconfiguring the circuit, testing changes - whether it be in wiring, resistance or capacitances - and using the software's built in voltmeter at different points until I had been able to bring the total variance up to.. 2 (from 0-2). From there, I changed the secondary ground pin from 5 to 3, which didn't work at all. However, once I reversed the polarity of the photodiode arbitrarily, the op-amp system suddenly worked. As much of a fluke this was, my work wasn't finished - about a quarter of the way up, the output values would sharply plateau at about 255, since it seems this was the maximum value the code allowed to output in this configuration (curiously, as of writing, the original version of the code works too). Nonetheless, after some research, I slightly tweaked the code by using the C++ `map `container to assign to a new outputValue variable:

```
outputValue = map(sensorValue, 0, 1023, 0, 255);
analogWrite(9, outputValue);
```

With that, the transimpendance amplifier circuit was now complete! :) It operates with values ranging from 0-1012, which is vastly better to filter out any noise which would previously have proved problematic.


2027-08-01
	Goal: Further my understanding of Waves & Optics
	Time spent: 4h20: N/A
	Activities : I decided to take a Sample Final Exam for the Waves, Optics & Modern Physics course from Dawson College. 
	This day was not particularly related to the Michaelson Interferometer in of itself, but rather the key concepts governing optics. This is going to be the exact topic of a course set for next semester, and is tangentially related to the project. I found myself with new ideas on how to approach the magnetostriction elements of the project - to prepare myself for the next semester. Doing an actual phase shift related problem is something which, before the interferometer, I had never encountered previously, and helped to understand and derive actual equations for this project. It is recommended check the questions out, they are quite well made :)


2027-08-02
	Goal: Post a devlog! Improve github documentation
	Time spent:
	Activities: Updated README.md to contain much more information than prior, as well as specific component listings which go a bit farther into specifics than this document does. Updated this documentation and posted my very first devlog.
	
	 Decisions:
	 D-007: I have decided to opt for a budget Cube beamsplitter option instead of relying on scrap parts from the DVD drive. This is to ensure 50R/50T behavior in the splitter glass. With budget in mind, I have found ~46$ alternatives to the prohibitively expensive Edmunds optics kits, allowing me to acheive much better precision in determining laser wavelength.
	 D-008: I have opted to use a Nickel wire for my magnetostriction testing. This is because, unlike pure iron, it only expands over field strength increases, and does much more so than iron. It is also relatively easy to source.
	 
A great source which helped me derive the equations seen at the start of this document and understand their meaning was the PHYWE magnetostriction document. [7]

Lingering Questions: What advantage could the optical phase shift calculation provide? How exactly does it translate to increased precision for magnetostriction - could there be other formulas which take advantage of it to attain more precise data that I am missing?
# **Sources for this document 
(bibliography.md file to be created later)**
[1]

“Magnetostriction with the Michelson interferometer,” Accessed: Aug. 02, 2026. [Online]. Available: https://phywe-itemservice.s3.eu-central-1.amazonaws.com/sites/DMS-Phywe/PROD/de-DE/item/phy_itemtestinstruction/P2/P2430811/P2430810_en.pdf

[2]

“Michelson Interferometer Lab Setup: Assembly and Alignment Guide,” _Edmundo ptics.com_, 2023. https://www.edmundoptics.com/knowledge-center/application-notes/optics/michelson-interferometer-lab-setup/?srsltid=afmbooqn2c4oqh7aiwxtvhnmm83wpudjhrfnunszm2f-co2m8ysokhul (accessed July 23, 2026).

[3]

“Michelson-Interferometer – Stoppi,” _Stoppi-homemade-physics.de_, 2026. https://stoppi-homemade-physics.de/michelson-interferometer/ (accessed July 23, 2026).

[4]

“BPW34 Photodiode Tutorial: Fast Light Sensing, Transimpedance Amplifiers (TIA), Arduino/ESP32 Interfaces, Ambient-Light Rejection, and Precision Optical Projects,” _Leobot Electronics_, 2019. https://leobot.net/tutorial/1116?srsltid=afmbooopagnvg12vstq3dtvbttizcvafkiru9jjx0otks_olei1qqyu_ (accessed July 26, 2026).

[5]

Khaled Magdy, “Arduino Photodiode Light Sensor (BPW34) Circuit & Code Example,” Jan. 2024. Accessed: July 27, 2026. [Online]. Available: https://deepbluembedded.com/arduino-photodiode-light-sensor-bpw34-circuit-code-example/

[6]

Jason, “UA741 Operational Amplifier: Exploring Its Key Features and Practical Applications,” 2025. Accessed: July 28, 2026. [Online]. Available: https://www.ic-components.com/blog/ua741-operational-amplifier-exploring-its-key-features-and-practical-applications.jsp

[7]
ibid, 1.
