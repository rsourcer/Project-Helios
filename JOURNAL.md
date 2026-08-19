**Engineering Log for Open Source Michaelson Interferometer**\
**Revision 0.2.3**\
Raoul Salemi\
This log is accurate as of 12/18/2026, 10:37 PM EST\
\
This document is to keep track of and formulate daily ideas along the course of this project. This will include any research, objectives, constraints and thoughts.

# **About this project**

The object's technical objective is to build a Michaelson Interferometer system which can:
- Takes a laser diode's output
- Splits the light through a beam splitter component
- Recombines it with the help of two mirrors, creating the interferometric patterns crucial to the experiment
- Expands the image onto a photodiode using a lens
- Detects interference patterns using a TIA photodiode system as one of the mirrors moves parallel to the laser light.
It can then:
- Accurately calculate wavelengths (defined later) based off mirror's movement from the micrometer's translation.
- Determine magnetostriction constant of a solenoid on which a mirror is mounted, based off the change in position of the aforementioned mirror.

**The formula for measuring wavelength as the mirror moves is**\
$$\lambda = \frac{2d}{\Delta N}$$  Where d is the distance between fringes and ΔN is the number of fringes observed.\
\
However, Michaelson Interferometers also prove very useful for a variety of experiments, one of such being magnetostriction. While the mirror attached to the micrometer stays static, this studies the change of distance in another mirror, facing the photodiode, once mounted to the edge of a ferromagnetic sample rod. As a magnetic field is contained inside it, the rod can either expand or contract, changing the mirror's position. We can therefore measure its magnetostriction constant by first, finding out how much the change in size of the coil through the movement of the mirror, with the formula:\
\
$$\Delta L = N_{fringes} \cdot \frac{\lambda}{2} $$\
Where N_{fringes} is the amount of peaks seen in the photodiode signal and λ is the laser wavelength. Then, use\
$$\lambda_m = \frac{\Delta L}{L_0}$$\
Where L0 is the length of the unmagnetized rod, and λm is the magnetostriction strain. Then, to find the field strength of the rod, H, we can use \
$$H = \frac{N \cdot I}{l}$$\
Where N is the number of turns in the coil, I is the current, and L is the length of the coil.
Finally, if we increase H (by raising the current) until dL plateaus and reaches a stable value, λm will be equal to the magnetostriction constant for the metal, λs.\
\
\
The optical phase shift of the light can also be calculated, and varies by \
$$\Delta \phi = \frac{4\pi \Delta L}{\lambda}$$
[1]
# **Components needed**

*Optical:*
- Laser Diode \
	The laser diode is what provides the system with an initial, focalized and uniform light source, crucial for the interferometry experiment as its intensity will be measured. It will be recycled from the DVD drive.
- Beam Splitting Glass (Cube/Flat)\
	This component splits the rays of light emitted by the laser light and sends them towards the parallel and perpendicular mirrors when at a 45 degree angle respective to the laser diode. It is important that this part splits the light evenly, as uneven distribution could alter results.
- 2x Reflective Flat Mirror\
	The mirrors reflect the light back to be recombined towards the beam splitter, which is what causes the interference effect - light acting on itself at the same place, cancelling itself out. λ/4 optical precision or higher would be wanted for such mirrors to ensure their accuracy for interferometry, while keeping them at a reasonable price point.

- Optional: Compensating glass plate\
	In multi-wavelength light applications, this is crucial for accuracy, and makes sure that light of all wavelengths travel through the same amount of glass no matter where the beam splitter sends them. Without it, with multiple wavelengths, refraction effects make the light much less useful for experimentation. This isn't needed at all if we have a cube beam splitter, as the light passes through the same amount of glass in those circumstances. [2]

*Mechanical:*
- Mirror adjustment system (M3 screws, plates, micrometer)\
	This is to adjust where the mirrors are on the system, fixing them in place yet allowing 1 axis of translational movement. One of the mirrors should also be connected to the rod inside the solenoid for magnetostriction testing. The other moves attached to a micrometer head: This will be used for determining the experimental wavelength of the laser. As the mirror moves
- Micrometer \
	This is to very precisely adjust the distance along which the mirror will move: as the mirror moves further into and out of the ray, the fringes will vary causing a change in light intensity in the photodiode. This signal is what will be used to calculate the wavelength of the light, depending on how far the mirror moves - therefore, high precision for its movement is important. It should also be able to lock into fixed position when the coil's magnetism is being tested, too.
- Mechanical Breadboard\
	This will be a solid starting plate to place all our components on, and fix them in place where they are desired.

*Measurement/Calibration:*
- Divergent Lens (Concave)\
	This enlarges the image of the interference fringes, allowing for calibration and visual testing (to make sure no unusual behaviour is produced). Short focal lengths preferred as the image should be enlarged quite a bit.
- Ground glass (any surface producing clean fringe image)\
	This is a surface to show the clear interference pattern enlarged by the lens.

*Electronics:*
- Photodiode sensor\
	This component picks up the recombined light emitted by the laser and sends electrical pulses based on the light's intensity.
- Amplifier\
	Amplifies the photodiode's detection of the laser, filtering out all other muddying noise.
- Arduino Uno (or alternative)\
	Processes the signal from photodiode, allowing the data to be analyzed from a computer.
- Rod\
	During magnetostriction tests, a mirror is mounted onto it, and the rod expands/contracts as a magnetic field induced by the solenoid flows through it.
- Solenoid/Coil: \
	During magnetostriction tests, this is what induces a magnetic field on the metal rod.

*Software:*
- KiCad (for electronics schematics (?))\
- TinkerCAD (for visual representation)\
- Python (programming of electronics (?))\
- any 3d printing software (I have experience in Blender and Fusion 360)\

# **Constraints** 

- BUDGET: 350 CAD
	The project must be a relatively low-cost solution. Professional interferometry equipment can be very expensive - at the time of writing, according to the website Edmunds, the cheapest available cube beam splitter alone, is 389 CAD, [3]. These beam splitters are considered rather standard for professional Michaelson optics projects. Using such optical grade components, it is highly unrealistic to build the interferometry platform within this budget range. It is to note that cheaper types of beam splitters do exist, and this budget will incentivize innovative usages for components. I will exclude shipping costs and taxes as I want to truly focus on the factor of value for the money the product itself costed - how much the manufacturer is selling it for.

- Recycled components
	While doing preliminary research in DIY interferometry, it struck my eye that many projects use recycled components to achieve their goals with relatively much power cost, while still retaining rather high precision. (3 Project Examples) Within that context, this project, too, must make creative use and source components from at least one recycled item - a component for which the intention of procurement was not originally interferometry or any other optical experimentation.
- Magnetostriction element
	The platform must be able to perform magnetostrictive tests on a solenoid, and determine its magnetostriction constant. This is the end goal of the interferometer, as it shows a real world application in which it can be used, beyond determining the wavelength of the laser diode. Doing so, it must also pass the precision aspect of the project.

- 3D Printing aspect
	To build a Michaelson interferometer, precise adjustment of distances is needed. Therefore, it would be reasonable to use my 3D printer, to this end. An important secondary goal of mine would be to test structural elements of pieces printed for this project from varying infill percentages and patterns, extrusion settings- etc, to make the most optimal 3D printed components for the interferometer. What defines "most optimal 3D printed components" will be defined later. My goal for this constraint is to further my knowledge of materials testing. 

- Precision aspect
	It would be futile to build an interferometer if it is not able to, well, interfere. Therefore, the uncertainty of the device's frequency measurements, once calculated (with electronic measurement technique - photodiode picks up signal from light intensity along the laser's shifting fringe patterns) must not be over +-10% in nanometers. For a given 650 nm light source, this means that the uncertainly should not be +-6.5 nm. There should be ≈10kHz bandwidth in the TIA circuit. During magnetostriction, λs should be calculated within a 10% margin of the expected value.

- Time aspect
	Given that the Stardance Hack Club project is ending on September 31st, it would be reasonable to finish this project by September 1st, 2026, as to not overlap with scholarly life. (to be removed?)

# **Assumptions**

	Laser wavelength ≈650 nm 
	Ambient temperature ≈20°C 
	System assembled indoors
	PETG-CF sufficiently stiff for preliminary testing
	

# **Acronym Legend**
Please refer to these if acronyms are used to describe components, such as in the project files.\
**Optical**
BS: Beamsplitter\
M1: Mirror 1 (Micrometer mirror)\
M2: Mirror 2 (Solenoid mirror)\
PD: Photodiode\
**Electronics**
PS: Power Supply\
NR: Nickel Rod\
S or SLD:  Solenoid\
AMP: op-amplifier
**Mounts**
BSM: Beamsplitter mount\
LDM: Laser diode mounting bracket\
LMB: Lens mounting bracket\
SMM: Solenoid mirror mount\
MMM: Micrometer mirror mount\
PMB: Photodiode mounting bracket\
# **Parts List**

**Laser Diode, springs:** From DVD Drive

**Mirrors :** 2x Thorlabs  **[PF05-03-P01](https://www.thorlabs.com/item/PF05-03-P01)**

**Beamsplitter:** Beam Splitter Cube, Optical Glass Dichroic Prism Ratio 50:50 Spectrome Sicence (20mm) ( Amazon) 
https://www.amazon.ca/gp/product/B0B34FK2GF

**Board, Wires, spare resistors:** ELEGOO UNO Project Basic Starter Kit with Tutorial and UNO R3 | Compatible with Arduino IDE (Amazon) 
https://www.amazon.ca/gp/product/B0834W2NKQ

**Capacitor set:** 10x10PCS 1KV High Voltage Ceramic Capacitor Kit | 100pF 220pF 330pF 470pF 1nF 2.2nF 3.3nF 4.7nF 10nF 22nF (Amazon) 
https://www.amazon.ca/gp/product/B0C5SKHXYD

**Op-Amp:** MCP601-I/P ( DigiKey MCP601-I/P-ND) 

**Photodiode:** BPW34 (DigiKey 475-BPW34-ND) 

**Resistor:** 0-100kOhm Trimmer (Amazon)

**Micrometer:** Inside Micrometer, 0-13mm Micrometer Flat/Ball Head (Amazon)
https://www.amazon.ca/gp/product/B083KHFKZ6

**Lens:** DM-WJ002 185 Biological Microscope Objective Lens Silver 10X Achromatic Objectives Lens 160/0.17 (Amazon)
https://www.amazon.ca/gp/product/B082P3P953

**Solid Mechanical Breadboard:** Genmitsu 3040 MDF Spoilboard, Work with 3040 Y-Axis Extension Kit, 3018 CNC Upgraded Accessories Compatible with Most 3018, 3018-PRO/ 3018-MX3, 30 x 36 x 1.5cm (11.8'' x 14.1'' x 0.6'') (Amazon)
https://www.amazon.ca/Genmitsu-Spoilboard-Extension-Accessories-Compatible/dp/B08VN6HXPD

**Magnetostriction rod:** SHONAN Nickel Anode- 7.87"x0.3"(Diameter) Nickle Anode, Pure Nickel Bar, Nickel Rod for Nickel Electroplating Solution, 3.4oz 99.6% 
https://www.amazon.ca/gp/product/B083LJWQYG

**Solenoid Wire:** # 123109-18GA Copper Wire 25FT 14LB
https://www.amazon.ca/gp/product/B000H5OL30


**Available already:**

2x DVD Drive (unknown model) 
Anycubic Kobra 3 + Ace Pro 2 
PETG-CF filament (1kg)
1kg Laser 190-2000nm protection glasses
NICE-POWER DC Power Supply Variable 30V 10A Adjustable Switching Regulated High Precision 4-Digits LED Display 5V/2A USB Port Output & Input Power Cord Bench Lab Power Supplies Digital Digital Multimeter
Soldering kit w/ wire, paste


Electric Drill w/ clamps for drilling through the wood board 
Computer 

**What I still need:** M3-6 screws required, with nuts, bolts and washers, assembly brackets, which can be 3D printed. These components can be purchased/created and implemented rather accessibly, so I figure that I should currently not worry about these until I have real world technical drawings.

# **Daily progress tracking**


	2026-07-23\
	Goal: Gain a concrete understanding of what I need for this project\
	Time spent: 48 min\
	Activities: Research, journaling (creation of this document, checking product listings\
	
	Decisions:  \
	 D-001 - I have opted to use an unused DVD drive to source many of the components for a Michaelson Interferometer\
	 
	Reason: This seems to be a common element of low cost solutions for this device: DVD drives come with laser diodes (640-660nm) , lenses and a semi transparent mirror, parts which have already been tested as useful for the creation of a Michaelson Interferometer in the past. [4]
	


Lingering Questions: What is the purpose of the compensator mirror? Why do some interferometer systems not use it? What precisional advantage could it offer?
Retroactive answer: The compensator mirror is used in multi-wavelength applications where the light must refract through the same amount of glass no matter where the beam splitter hits to obtain an accurate recombined image. Therefore, this glass serves to compensate for the side which bounces off the beam splitter initially. IT does not offer a precisional advantage in single wavelength applications. 

--------------------------------------------------------------------------

	2026-07-24\
	Goal: Better my mental picture of the required assembly\
	Time spent: \
	Activities: Setting up KiCad, sketching rough paper blueprint, researching required electronic components\
	
	Decisions:  \
	 D-002 - I have opted to have two variations of the system - one to calibrate the interferometer, consisting of a lens and a surface where the fringes will be visible - and one consisting of the electronic measuring components. This is to maximize the ease of precise set-up and reliable measurement precision of the respective methods.\
	 
	D-003 - I have opted to use an Arduino Uno R3 compatible clone rather than the official product to save cost. The Elegoo R3 is currently the most seemingly promising option. This will allow to maximize value elsewhere.\
	


Lingering Questions: Why must we need a capacitor and resistor for the circuit? How will using or not using an amplifier play into the measurement system?
Answer: When a photodiode receives light, it does not modify the voltage of the circuit in of itself, but the amount of current flowing through it. This is what allows us to get a signal. However, without an amplifier, the difference in current produced by the light can be minimal and prone to noise, greatly decreasing its efficiency. Therefore, the amplifier helps to mitigate the effects caused by noise, and get a much clearer picture of the laser's signal.

--------------------------------------------------------------------------
2026-07-26\
	Goal: Completely understand electronics aspects of the interferometry\
	Time spent: \
	Activities: Research on electronics equipment needed. Beginning a rough KiCad schematic.\
	
	Decisions:  \
	 D-004 - I have decided on what parts I will use - I will couple the Elegoo R3 as discussed yesterday with a BPW43 photodiode, as it is a photodiode suited for near-IR range, inexpensive and has lots of educational resources available. Coupled to these two components could be a UA741 op-amp, which seems to be a common pairing with this photodiode.[5]\
	
One thing which helped me today was the BPW43 photodiode tutorial [6], which helped me to further understand how the electronics of this project will function. \

Lingering Questions: Given my needed applications, should I really use KiCad? Should I create a PCB, or invest in a breadboard? What advantages and disadvantages would there be to this? Is this still a question for which it is too early to tell?\
Answer: ...No. There is no real benefit to remodel the circuit on KiCad as TinkerCAD already has a schematic model which works fine.


-------------------------------------------------------------------------------------------------------------
2027-07-27
	Goal: Finalize real electronic design and schematic\
	Time spent:\
	Activities: Journal refining, Researching TinkerCAD to further progress on electronics for my project\
	
	Decisions:  \
	 D-005 - I decided to use TinkerCAD to create a model of the TIA photodiode circuit, as many templates are available to choose from - this will make it easy for me to verify my circuit logic. It also has a much smaller learning curve than KiCad does.\
	
One thing which helped me today was the TinkerCAD photodiode preset, which shows how to make a (albeit less complicated) version of the photodiode system I seek to create. Using this, I can easily gain a clearer picture of what the electronics are supposed to look like once adapting it into a TIA design, as opposed to immediately jumping into KiCad and hoping to understand - what I felt I was doing in the previous days of research. This also allows me to pre-emptively program the circuit long before getting around to building it. (and, of course, some real world aspects are overlooked in TinkerCAD, so I can only use the code blocks offered as simple guidance). My course of action is now to use the simplified TinkerCAD model to understand the wiring, then, replicate it on KiCad now that I have improved my knowledge on how to use the program.


------------------------------------
2026-07-28\
	Goal: ACTUALLY finalize electronic design. Yesterday, I ran into a problem with the circuit which rather confused me. Today, I want to focus on getting this template TIA circuit running properly, as to understand what is going on.\
	Time spent:\
	Activities: Rewiring TinkerCAD Circuit, debugging said circuit.\
	
	 Decisions:\
		 D-006: I am reconsidering the usage of the UA741 op-amp, as it seems to be an unfit match for the current application. The supply is 5V, meaning that it falls on the short end of its rated voltage range (~4.5-40V) [7] While it could still be viable, other op-amps such as the OPA381 could be more effective for the task at hand. This would translate into real world implications for bettering our precision and accuracy results when testing our interferometer.\
	
	
I ran into many problems while debugging the TinkerCAD circuit to be operational. I based myself off a pre-existing default photodiode circuit template (credit to Tom Igor for the C++ code) and had to retrofit it into the TIA circuit system I will use. However, the amplifier proved to be very tricky to wire. Using my online resources, I had been able to get it in a way as to work in reducing the measured signal, which made the variance in intensity go from about 203 (from 10-213) to only 1 (from 512-513). I spent hours reconfiguring the circuit, testing changes - whether it be in wiring, resistance or capacitances - and using the software's built in voltmeter at different points until I had been able to bring the total variance up to.. 2 (from 0-2). From there, I changed the secondary ground pin from 5 to 3, which didn't work at all. However, once I reversed the polarity of the photodiode arbitrarily, the op-amp system suddenly worked. As much of a fluke this was, my work wasn't finished - about a quarter of the way up, the output values would sharply plateau at about 255, since it seems this was the maximum value the code allowed to output in this configuration (curiously, as of writing, the original version of the code works too). Nonetheless, after some research, I slightly tweaked the code by using the C++ `map `container to assign to a new outputValue variable:

```
outputValue = map(sensorValue, 0, 1023, 0, 255);
analogWrite(9, outputValue);
```

With that, the transimpendance amplifier circuit was now complete! :) It operates with values ranging from 0-1012, which is vastly better to filter out any noise which would previously have proved problematic.


2026-08-01\
	Goal: Further my understanding of Waves & Optics\
	Time spent: 4h20: N/A\
	Activities : I decided to take a Sample Final Exam for the Waves, Optics & Modern Physics course from Dawson College.\ 
	This day was not particularly related to the Michaelson Interferometer in of itself, but rather the key concepts governing optics. This is going to be the exact topic of a course set for next semester, and is tangentially related to the project. I found myself with new ideas on how to approach the magnetostriction elements of the project - to prepare myself for the next semester. Doing an actual phase shift related problem is something which, before the interferometer, I had never encountered previously, and helped to understand and derive actual equations for this project. It is recommended check the questions out, they are quite well made :)


2026-08-02\
	Goal: Post a devlog! Improve github documentation\
	Time spent:\
	Activities: Updated README.md to contain much more information than prior, as well as specific component listings which go a bit farther into specifics than this document does. Updated this documentation and posted my very first devlog.\
	
	 Decisions:\
	 D-007: I have decided to opt for a budget Cube beamsplitter option instead of relying on scrap parts from the DVD drive. This is to ensure 50R/50T behavior in the splitter glass. With budget in mind, I have found ~46$ alternatives to the prohibitively expensive Edmunds optics kits, allowing me to acheive much better precision in determining laser wavelength.\
	 D-008: I have opted to use a Nickel wire for my magnetostriction testing. This is because, unlike pure iron, it only expands over field strength increases, and does much more so than iron. It is also relatively easy to source.\
	 
A great source which helped me derive the equations seen at the start of this document and understand their meaning was the PHYWE magnetostriction document. [8]\

Lingering Questions: What advantage could the optical phase shift calculation provide? How exactly does it translate to increased precision for magnetostriction - could there be other formulas which take advantage of it to attain more precise data that I am missing?

2026-08-03
	Goal: Figure out WHAT I am buying for this project\
	Time spent: 3h11min\
	Activities:\
	1: I started by doing the most expansive research to date on my mirrors. This is because they are one of the only optical components I cannot substitute with parts found in the used DVD drive. Since the beginning of this documentation, I have been eyeing out various mirrors from Edmund's Canada due to concerns about shipping time and optical quality on other websites. However, I have began to move away from this idea, and I think I have found just the match for my project. I researched other websites which could fit my price range while still satisfying my needs and shipping in the allocated time, and found it difficult to be certain while shopping for Canadian only products - maybe not even currently being in Canada, is of no help.
	

---

| Mirror                                                                                                                                             | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                        | Cost per mirror (CAD) |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | --------------------- |
| 1: Edmunds  [**5mm Dia Enhanced Aluminum, 4-6λ Mirror**](https://www.edmundoptics.com/p/5mm-dia-enhanced-aluminum-4-6lambda-mirror/2709/)          | Very low precision (4-6 λ), especially for magnetostriction applications. Least expensive option - also comes in very small. 450-650 nm range.                                                                                                                                                                                                                                                                                                                     | 39.90$                |
| 2: Edmunds<br> [**15 x 21mm Enhanced Aluminum, 4-6λ Mirror**](https://www.edmundoptics.com/p/15-x-21mm-enhanced-aluminum-4-6lambda-mirror/5358/)   | Same thing as the other mirror, but at least this one is much larger despite being at the same cost. 450-650 nm range.                                                                                                                                                                                                                                                                                                                                             | 39.90$                |
| 3: Edmunds [**5mm Dia. Enhanced Aluminum, λ/4 Mirror**](https://www.edmundoptics.com/p/5mm-dia-enhanced-aluminum-lambda4-mirror/8652/)             | This mirror is much better in terms of precision. It has a Surface Flatness (P-V) of λ/4, which is much better for my application. However, it is very small AND costly. 450-650 nm range.                                                                                                                                                                                                                                                                         | 89.60$                |
| 4: Edmunds <br> [**12.5mm Dia. 400 - 750nm Broadband λ/4 Mirror**](https://www.edmundoptics.com/p/125mm-dia-400---750nm-broadband-4-mirror/54000/) | Handedly, broadband dielectric mirrors are much better for my range. They are also even more expensive. (200-700nm)                                                                                                                                                                                                                                                                                                                                                | 97.30$                |
| THORLabs **[PF03-03-F01](https://www.thorlabs.com/item/PF03-03-F01)**                                                                              | λ/10 surface flatness is incredible at this price point. It is unfortunately not intended for the laser's wavelength, so their table shows that roughly 82-83% of laser power should reach the photodiode A bit small, at 7mm. 250-450nm range.                                                                                                                                                                                                                    | 33.99 USD → 47.64$    |
| THORLabs **[PFSQ05-03-F01](https://www.thorlabs.com/item/PFSQ05-03-F01)**                                                                          | This is the PF03-03-F01's slightly larger, square twin. It is slightly larger (12.7mm) and therefore cheaper per area of mirror purchased. Shipping time is reasonable, yet cost is 35.44 USD. Isn't accounted for but still significant.                                                                                                                                                                                                                          | 39.74 USD → 55.70$    |
| THORLabs **[PFSQ05-03-P01](https://www.thorlabs.com/item/PFSQ05-03-P01)**                                                                          | This mirror is the same price and flatness as the PFSQ05-03-F01, however it is in silver rather than aluminium, thicker (possible disadvantage with the rod) and much more reflective at 450nm (97%). However, not much more details are present concerning the mirror's reflectiveness from 640-660nm.14 day shipping time for my location. Curiously, shipping costs are almost double (68.55$ USD) though these are technically not accounted for in my budget. | 39.74 USD → 55.70$    |

2026-08-03 (contd.)
	
	Decisions \
	D-009: I ended up deciding on the THORLabs PFSQ05-03-F01 for my interferometer. This is as the estimated shipping time is much more reasonable, yet the mirror retains the λ/10 flatness found in all THORLabs options.\
	
2026-08-05\
	Goal: Finish a full parts list for my project.\
	Time spent: \
	Activities: Buying the mirrors, which costed, 79.48 USD (110.78 CAD as of 2026/08/05) Creating a full parts list for ChatGPT to give feedback and to check personally if I had missed anything. The full parts list is, at this current time, included near the top of the journal. However, Here are my justifications for every purchase:\

---
1: Beam Splitting Glass

| Beamsplitter                                                                                                                      | Justification                                                                                                                                                                                                                                                                                                                                                                                                 | Cost (CAD) |
| --------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **[Beam Splitter Cube, Optical Glass Dichroic Prism Ratio 50:50 Spectrome Sicence](https://www.amazon.ca/gp/product/B0B34FK2GF)** | This item is low cost and fabricated with K8 Cristal, which is a material of sufficient grade for my project. The cheapest size is 20mm, which is more than enough. However, no precise manufacturer details are listed. I posit that it will still be good enough - cube beam splitters are preferred to flat beam splitters in terms of precision in Michaelson interferometer projects and similar optics. | 43.47$     |
This is frankly the only option I have considered which ships in reasonable time at this price point. Flat beam splitters of this material are available, but cube beam splitters are advantageous for my application. [9]

2: Board kit

| ATMega328P R3 Kit                                                                                                                                                                                                                     | Justification                                                                                                                                                                                                           | Cost (CAD) |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **[ELEGOO UNO Project Basic Starter Kit with Tutorial and UNO R3 \| Compatible with Arduino IDE](https://www.amazon.ca/gp/product/B0834W2NKQ)**                                                                                       | This item comes with a pack of seemingly assorted resistors and jumper cables, as well as an aftermarked ELEGOO Arduino R3. It is at a reasonable price.                                                                | 29.99$     |
| **[ELEGOO UNO R3 Board ATmega328P with USB Cable(Arduino-Compatible) for Arduino](https://www.amazon.ca/dp/B01EWOE0UU)**                                                                                                              | Standalone version of the Basic Starter Kit. Cheaper, but buying jumper cables and assorted resistors separately comes out to being more expensive than the former option.                                              | 21.99$     |
| **[UNO R3 Starter Kit – 40PCS Electric Circuit & Electronics Learning Kit, UNO R3 Compatible Board with Breadboard, Sensors, RFID, Motors & Components](https://www.amazon.ca/UNO-Starter-Kit-Electronics-Compatible/dp/B0GMV21S6J)** | Includes an official Arduino R3 board. I was considering this option as I believed it included a set of capacitors, but was mistaken. Includes a set of many other useful sensors, though not relevant to this project. | 39.99$     |
I decided on the Basic Starter Kit for now, as the extra components could prove especially useful.

3: Resistor Set
	These will be bought to not rely on the board kit's resistor set - some of the items do not label the resistances and vary at each image. They also, to my knowledge, don't include anything even near the 50k Ohm range which I used for testing in TinkerCAD. I decided to buy sets of 10, as resistors can trip, and I would like more to be cautious. Unit prices also become cheaper at 10 units for DigiKey products. 

| Resistor Set                                                                                                                                                                                                                                                                              | Justification                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | Cost/unit (CAD) |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | --------------- |
| **[DigiKey CF18JT47K0CT-ND](https://www.digikey.ca/en/products/detail/stackpole-electronics-inc/CF18JT47K0/1741721?s=N4IgTCBcDaIMIDECMAOAUgFQCwHYDSADHBgLQByAIiALoC%2BQA)** (10)                                                                                                          | This item is a 47k Ohm resistor, which is apt for my use case, as my TinkerCAD model was represented with 50k Ohm. It is also rather inexpensive per unit. rated at 0.125W                                                                                                                                                                                                                                                                                                                       | 0.036$          |
| **[DigiKey TC33X-2-104E](https://www.digikey.ca/en/products/detail/bourns-inc/TC33X-2-104E/612859?s=N4IgTCBcDaICoGEDMSAaBaM6CMAGALAKIgC6AvkA)** (10)                                                                                                                                      | This is not a resistor, but rather, a 100k Ohm trimmer. This means I can adjust the resistance and set it to what I want using the multimeter and screwdriver. However, this comes with different ways of calculating uncertainty. Tolerances very high at 25%, rated at 0.15W. It's also 1 turn only, making it hard to adjust precise resistance. It is also not insulated by any means, therefore dust and feedback capacitance, as well as acoustic effects impact its effective resistance. | 0.36$           |
| **[Resistor 47k Ohm 1/4 Watt 5% Carbon Film: 47kohm 1/4W](https://be-electronics.com/products/resistor-47k-ohm-1-4-watt-5-carbon-film-47kohm-1-4w?variant=47099826733292)** (10)                                                                                                          | This is a fixed 47k Ohm resistor sourced domestically from another website. rated at 0.25W.                                                                                                                                                                                                                                                                                                                                                                                                      | 0.22$           |
| **[Vishay Spectrol 64X104 Trimmer Potentiometer 100k Ohm 0.5 Watt 25 Turn, PCB Mount Trimpot, Side Adjustment *CLEARANCE*](https://be-electronics.com/products/vishay-spectrol-64x104-trimmer-potentiometer-100k-ohm-0-5-watt-25-turn-pcb-mount-trimpot-side-adjustment-clearance)** (10) | This is also a trimmer, but sourced in Canada. It is much more expensive yet rated at 0.5W. It is to note that this is a closed, 25 turn trimmer, meaning that external variation is minimized and fine tuning is easier.                                                                                                                                                                                                                                                                        | 1.69$           |
| **[uxcell 10Piece 3296W-104 100K Ohm Trimmer Pot Cermet Potentiometer \| Variable Resistors](https://www.amazon.ca/gp/product/B00D2JRALS)** (Amazon)                                                                                                                                      | Cheaper closed 25 turn trimmer set, rated at 0.5W.                                                                                                                                                                                                                                                                                                                                                                                                                                               | 1.25$           |

I've realized that wattage doesn't particularly matter much for our circuit's application, as the Arduino R3 takes in 5V from the USB and at 57k Ohm, by $$P = V^2/R$$ our power in the circuit should be around, at most, 4.38596e-4 W, which is below what any of these resistors are rated for.
I therefore decided on the Amazon trimmer, so we could experiment with a greater range of many different capacitances rather than one fixed number, while being sure that external inaccuracies are mitigated.

4: Capacitor Set
It is to be known that in our preliminary Tinkercad testing, a greater capacitance means that the amplification is smaller, so the circuit operated on 100pF capacitors. In a real world application, I also know I need a 

| Capacitor Set                                                                                                                                                                                            | Justification                                                                                                                                                              | Cost (CAD) |     |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | --- |
| **[10x10PCS 1KV High Voltage Ceramic Capacitor Kit \| 100pF 220pF 330pF 470pF 1nF 2.2nF 3.3nF 4.7nF 10nF 22nF](https://www.amazon.ca/gp/product/B0C5SKHXYD)**                                            | Includes a wide variety of different capacitances, allowing me to tweak the circuit to a degree further than what I have theoretically simulated on the Tinkercad website. | 10.99$     |     |
| **[300pcs 15Values High Voltage Ceramic Disc Capacitor Assortment Kit (1KV 2KV and 3KV) (Capacitor Range : 0.1nF~22nF)](https://www.amazon.ca/XLX-15Values-Voltage-Capacitor-Assortment/dp/B01M3W0SW1)** | Includes an even greater variety, yet comes at a slightly higher cost.                                                                                                     | 14.99$     |     | 






DigiKey sold only individual capacitors, limiting experimentation, which seemed to be, at the cheapest, 4$ per unit, which was far too expensive to even consider. I decided on the first option as it allows for the same range of testing as the other at a lower price point.

5: Photodiode

| Photodiode                                                                                                   | Justification                                                                                                                                                                                                                                                                      | Cost/unit (CAD) |
| ------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------- |
| **[Digikey BPW34](https://www.digikey.ca/en/products/detail/ams-osram-ag/BPW34/607274)**                     | This photodiode is rated for the correct spectral range for this project (~400-1100nm). It is also a common, versatile pick for a photodiode. Unfortunately, the standard lead time is listed at 14 weeks. Cheaper. Ships from Canada, shipping time is unknown (claimed 1-3 days) | 2.89$           |
| **[Amazon BPW34](https://www.amazon.ca/Photodiode-BPW34-BPW34S-Silicon-Sensitivity/dp/B0F4CNXCMX) (5 pack)** | Same photodiode. Slightly more expensive yet shipping time guaranteed (~2-3 days)                                                                                                                                                                                                  | ~3.07$          |

6: Op-Amp
I will probably not buy 10 of these, as I don't believe I will be advantaged by purchasing such a quantity given the cost of the product. I reason that 3 will be okay for my use case, as I would have 2 backups - just in case.

| Amplifier                                                                                                                                                                   | Justification                                                                                                                                                                                                                                                                           | Cost (CAD) |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **[IC 741CP - DigiKey, 296-11107-5](https://www.digikey.ca/en/products/detail/texas-instruments/UA741CP/382197?s=N4IgTCBcDaICIEsDmCDSBTAngGgARgE4A2AWgEYKAGAdhIFYQBdAXyA)** | The IC 741 is the op-amp which was used as a template in Tinkercad, at seems to be a rather widespread amplifier option. However, in the real world, it seems to run on dual supply from +-5V to +-15V whereas this Arduino circuit operates on a single 5V supply, which is unoptimal. | 1.02$      |
| **[TLV2372IP - DigiKey 296-12219-5-ND](https://www.digikey.ca/en/products/detail/texas-instruments/TLV2372IP/413506)**                                                      | Single supply operation from 2.7-16V. More expensive yet optimized for my use case. Broad range of voltages. Requires rewiring of the Tinkercad circuit.                                                                                                                                | 3.33$      |
| **[OP341UA - DigiKey 296-43421-5-ND](https://www.digikey.ca/en/products/detail/texas-instruments/OPA341UA/416723)**                                                         | Single supply operation from 2.5-5.5V Most expensive option. Requires rewiring of the Tinkercad circuit.                                                                                                                                                                                | 6.84$      |
| **[MCP601-I/P - DigiKey MCP601-I/P-ND](https://www.digikey.ca/en/products/detail/microchip-technology/MCP601-I-P/305930?s=N4IgTCBcDaILIGEAKA2ADARgLQEkD0SIAugL5A)**         | Single supply operation from 2.7-6V. Cheapest option, all used pins match                                                                                                                                                                                                               | 0.98$      |
 I have decided in favor of the MCP601-I/P as it fits the exact layout that my circuit is inherently designed for. The other op-amps need pins changed.

7: Micrometer

| Micrometer                                                                                                                                                                                                              | Justification                                                                                                                                                                                            | Price (CAD)      |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------- |
| **[Electronic Digital Caliper, LCD 0 to 6 inch inch/mm Conversion, Automatic Shutdown Function, White/Black](https://www.amazon.ca/gp/product/B08ZNQRB39)**                                                             | This isn't a micrometer. Caliper's range is of 150+-0.2mm. Digital. It uses the metric system, which is preferred as that is what I am more familiar with (and what everything else in the circuit uses) | 10.99$           |
| **[Spurtar Vernier Caliper Measuring Tool 6 inch/150mm, Non Digital Calipers \| 0.001"/0.02mm High Precision, Durable Micrometer, Measuring Tool, Dual Imperialand Metric Scale](https://www.amazon.ca/dp/B074HZ8S21)** | This isn't a micrometer. More expensive, and mechanical. This caliper's range is of 150+-0.02mm, which is much more precise. Its build quality also appears to be higher.                                | 17.98$ (33% off) |
| **[Inside Micrometer, 0-13mm Micrometer Flat/Ball Head](https://www.amazon.ca/Micrometer-Fine-Tuning-Various-Accuracy-Instruments/dp/B083KHFKZ6)**                                                                      | 13+-0.01mm precision micrometer. Also doesn't include the c frame, which is useful for my applications. Range is rather limited, though this is not an issue.                                            | 18.47$           |
| **[HDLNKAK Outside Micrometer 0-1",0.0001" Precision Graduation Micrometer Set \| Ultra-Precision Standard Micrometer Carbide Tipped Measuring Tool with Case](https://www.amazon.ca/dp/B0CF917TB5)**                   | 1"+-0.0001' precision micrometer. More expensive, and The c frame needs to be removed. Additionally, it makes use of the imperial system.                                                                | 19.99$           |
Considering every product, I have decided on the third listing, as a micrometer head is easier to create a 3d printed mount for than the other options. It also offers the highest precision using the metric system out of these products.

8: Lens
According to previous sources, [10] DVD drives contain concave and convex lenses which could work for my Michaelson interferometer. According to me, true optical concave lenses of relatively short focal length (<20mm) are not very readily available at a reasonable price considering the budget. Here are some options I found:


| Lens                                                                                                                                                                                                                                               | Justification                                                                                                                                                         | Price (CAD) |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| **[Tangxi 30X Jewelry Magnifier, Professional Optical Magnifier Glasses, 30X Magnifying Lens](https://www.amazon.ca/gp/product/B07X49J7PM)**                                                                                                       | 30X divergent magnifying lens which seems solid in material. However, unknown exact focal length. It is also not purpose built and therefore could be very unoptimal. | 13.48$      |
| **[PATIKIL 12 Pcs Convex Lens, 12mm OD 17mm Focal Length Magnifier Lens Optical Lenses Borosilicate Magnifying Glass Flat Convex](https://www.amazon.ca/dp/B0G3PBDDG1)**                                                                           | 17mm focal length, small convex lens (perhaps too small).                                                                                                             | 10.99$      |
| **[KIMISS 4X Achromatic Objective Lens for Biological Microscope 160/0.17 High-Quality Achromatic Objectives for Clear Imaging in Scientific Research](https://www.amazon.ca/KIMISS-Achromatic-Biological-Microscope-High-Quality/dp/B0D4PCV9CC)** | Achromatic objective lenses work much better for my application. This 4X enlargement lens has a longer focal length than the other options                            | 14.17$      |
| **[DM-WJ002 185 Biological Microscope Objective Lens Silver 10X Achromatic Objectives Lens 160/0.17](https://www.amazon.ca/gp/product/B082P3P953)**                                                                                                | Same as 3rd option, but with 10x enlargement, and slightly more expensive.                                                                                            | 18.83$      |
Considering the final two products, I decided to opt for the 10X achromative objective lens as the shorter focal length will contribute to making my setup more compact (surface which the fringes are observed on is closer to the rest of the system).

9: Mechanical Breadboard
This WILL come back later, as I did not do a thorough comparaison. For now, I decided on:


| Sheet                                                                                                             | Justification                                                                                                                                                       | Cost (CAD) |
| ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **[Basswood Sheets 12 Pack, 12"x12"x1/16" Thin Unfinished Plywood](https://www.amazon.ca/gp/product/B0D4CD82S3)** | This plywood sheet shouldn't deform all is easy to drill holes in, comparing to previously considered metal sheet. However, it warps to humidity/thermal expansion. | 29.99      |

10: Magnetostriction Rod

| Rod                                                                                                                                    | Justification                                                                                      | Cost (CAD) |
| -------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- | ---------- |
| **[SHONAN Nickel Anode- 7.87"x0.3"(Diameter) Nickle Anode, Pure Nickel Bar, Nickel Rod](https://www.amazon.ca/gp/product/B083LJWQYG)** | Quick shipping time. 8mm diameter below the dimensions of my mirror (12.7mm). 99.6% rated          | 23.10$     |
| **[TEN-HIGH Nickel Anode Pure Nickel Bar 3.94" x 0.39", 99.6% Nickel Rods](https://www.amazon.ca/dp/B0BW47Q79T)**                      | Half the length of the other rod, but considerably more expensive. The diameter is larger at 10mm. | 58.44$     |
I decided to opt for the first item.
11: Solenoid Wire

| Wire                                                                                | Justification                                                                                                                                              | Cost (CAD) |
| ----------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| **[23109-18GA Copper Wire 25FT 14LB](https://www.amazon.ca/gp/product/B000H5OL30)** | This should be enough copper wire for a solenoid with 30V running through it to create a proper magnetic field, strong enough for magnetostriction. Cheap. | 9.99$      |


---

2026-08-06 
	Goal: Catch up on documentation - while I have made very rough documentation in the past few days on my phone, I want to further it in a way which can be shown on my journal in a more concrete way. I am also running late on it and would like to update it before I continue on to do new things.
	Time spent: 2h1m (1h0min logged on Stardance)
	Today, I learnt that I had incorrectly bought UV Enhanced versions of the mirrors while NON UV versions existed and had the same shipping conditions and price, yet reflectance at almost 95%. This would give me the same level of precision yet higher efficiency, making it slightly easier to calibrate. However, I figured that this would not be too significant for my testing, as the TIA photodiode circuit I have employed can simply adjust to this lower power with a bigger resistor.
	I am also questioning my choice for the board. The **basswood breadboard** I previously chose may be easy to drill, but basswood can be flexed and deform quite a bit, which may be problematic for my experimentation. This is why I had originally set out to find an aluminium pre drilled board. Here are the options I considered today:


---
Firstly, the criteria for which I choose the material had to be identified. I wanted something which, ideally, was:
-Easy to work with
-Doesn't deform under stress in any meaningful way
-Fits within allocated budget (<30$)
-Thickness >=10mm
-Board dimensions > 250x250mm
-Ships to Canada in under 7 business days

| Material                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          | Explanation                                                                                                                                                                                                                                      | Cost   |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------ |
| **[Basswood Sheets 12 Pack, 12"x12"x1/16" Thin Unfinished Plywood](https://www.amazon.ca/gp/product/B0D4CD82S3)**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 | 12 pack of 12x12" 1/16" thickness boards is frankly, too thin. This plywood sheet shouldn't deform all is easy to drill holes in, comparing to previously considered metal sheet. However, it is very susceptible to humidity/thermal expansion. | 29.99$ |
| **[Performore Expanded PVC Sheet – Lightweight Rigid Foam – 3mm (1/8 inch) – 12 x 12 inches – Black](https://www.amazon.ca/Expanded-PVC-Sheet-Lightweight-Displays/dp/B08PC743GY)**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               | 2 pack of 12x12' 1/8' thickness - still very thin. A solid PVC sheet will not deform as much as wood under load and can be screwed cleanly along any surface point.                                                                              | 25.34$ |
| **[Genmitsu 3040 MDF Spoilboard, Work with 3040 Y-Axis Extension Kit, 3018 CNC Upgraded Accessories Compatible with Most 3018, 3018-PRO/ 3018-MX3, 30 x 36 x 1.5cm (11.8'' x 14.1'' x 0.6'')](https://www.amazon.ca/Genmitsu-Spoilboard-Extension-Accessories-Compatible/dp/B08VN6HXPD/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.JDHfCXZGKzIy9O-G0ekCuLHUtugqV1kTDwOUz1e-RIKvs2PRxbk9W1L39JP-1Fdjm10xW8zCU7oG0XM5ngYwKPQWA47XrOcipiwrZsy3XbufHtEi3WcAk9SXZQxjJiEn9RZeMZa43NOc9RTTqmtnI70PFuGJg9FNfGbayugO1MdiH4_ugCKh93wEnPZb9ffPrhBOiuxI8_WYT5G8JmmId8YFHtqdEToVvGFPxqLXNlv-tH-M2TCUH05SKtHAJsFlFnG3OC3FXbWMPyyhCgHYIybDiXr3vOIKex7grzPranU.idJJhqyuwm-spd5E3AqzVTU3nr9HpEGw9Dpynzzju8k&dib_tag=se&keywords=genmitsu%2Bmdf%2B3040&qid=1786280300&s=hi&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1)** | 30x36cm 1.5cm thickness size is fair. Comes with precise, pre threaded M5 screw holes and locknuts, along with some other items as a kit. Technically designed as a CNC spoilboard, and less material in volume.                                 | 29.74$ |
| **[DEAYOU 10 Pack 11" x 14" MDF Wood Boards for Crafts, 1/4" Thick Medium Density Fiberboard, Unfinished Art Chipboard Sheets, Blank Wooden Hardboard Panels](https://www.amazon.ca/DEAYOU-Fiberboard-Unfinished-Chipboard-Hardboard/dp/B0F6N2MY9L)**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             | 10 pack of 11x14' 1/4' thickness boards. This mdf sheet is easy to drill yet, over twice as thin as the 3rd option and therefore much more susceptible to humidity/thermal expansion.                                                            | 27.99$ |

With these different boards in consideration, I decided on the Genmitsu 3040 MDF Spoilboard, as the pre-drilled holes seem to be extremely useful for my use case, and almost replicate actual, much more expensive optical boards. 

**Now, the materials list was finally done.**

2026-08-07\
	 Goal: Finish catching up on documentation.\
	 Time spent: 1h0min (37min logged on Stardance)\
	 Activities: Filling in this document with various comparaisons of different items. \
	Today's global analysis of every item primarily gave me a full global understanding of every part of the project, as I had to now give explanations to the disadvantages and advantages of every option, for every component. Previously, I had justified the components only very briefly, so this gave me a clear picture as to ***what** I am doing, and **how** I will do it. Much of my time was spent indexing all the items, embedding them on this document as a clear demonstration of product research.
	

2026-08-08\
	Goal: Finish listing components, make final design choices\
	Time spent: 4h37min ( logged on Stardance)\
	Activities: Continuing the item comparaisons for every product, and creating a rough perspective sketch of every component of the Michaelson Interferometer - the overarching system - in action. \
	
	Decisions\
	 D-010: I decided to rethink how the system works- the mirror not attached to the magnetostriction subsystem will be attached to the moving micrometer and move during the laser wavelength experiment.\

Previously, I wrongly designed the system to have two fixed mirrors and a photodiode which moves along, perpendicularly to the laser image expanded by the lens, using the photodiode, thinking the math would be the exact same (Spoiler alert - its not). The mirror movement makes the fringes/interference patterns change predictably, but moving along the fringes mechanically along a spherically expanded image is much more complicated to calculate. The equation for determining wavelength with a perpendicularly moving photodiode with an expanded image can be found from Young's Double Slit experiment:\
$$y =  \frac{\lambda \cdot D} d$$ where D is the distance from the source focal plane to the photodiode, d is the separation between virtual sources (what stretches/compresses fringe pattern) and y is the width of one fringe, determined by dividing the distance travelled by the photodiode by the number of peaks (fringes) measured, giving the equation:\
$$ y = \frac{ \Delta x} N $$ (delta x is the distance travelled and N is the number of fringes). [11] Then, we can substitute this into the former equation and isolate for the wavelength, giving the equation\
$$\lambda = \frac{\Delta x \cdot d} {N \cdot D} $$ we are able to measure the change in distance of the photodiode, the distance from focal plane to the photodiode and the number of peaks/fringes. However, there is not a way to find or cancel out the separation of virtual sources, d. Determining this value according to our system's alignment would require using a laser with a known, precise pre-determined wavelength, which goes against the premise of using a DVD drive. It is also to be known that micrometer level changes in alignment of the mirror, laser or beamsplitter can alter this value to the point where measuring wavelength becomes unfeasible using this concept without engineering methods to align each component with maximal precision. In comparaison, the equation for finding the wavelength from fringe signal with a moving mirror is, as stated earlier,\
$$\lambda = \frac{2d}{\Delta N}$$
(d is the distance between fringes and ΔN is the number of fringes observed) it not only has less variables needed to precisely keep track of, but we can determine all these values without solving based off a known wavelength value. Therefore, it makes much more sense to use this system, where both mirrors can move - one mechanically, the other based off magnetostriction - for our testing. \

2026-08-09\
	Goal: Ordering components, finishing up documentation on said components\
	Time spent: 3h9min (1h5min logged on Stardance)\
	Activities: Finally catching up to progress in the document! Ordering the rest of the online components which I cannot easily source physically. I also verified that the logic for the above equations made sense.\
	
	Decisions\
	D-011: I decided to change the resistor I was considering from the Digikey to the Amazon trimmer option. This is because spending more money to have insulation offers protection to external factors such as dust, sound and parasitic feedback capacitance, making sure that my TIA circuit stays exactly how I want it to be. \

**Purchase cost so far: 324.09 CAD** across DigiKey, Amazon and THORLabs. This is good! There are 25.91$ left for extra materials, such as the missing m5 screws, or if I ever need more filament.

2026-08-10\
	Goal: Creating a proper technical drawing for the next devlog to show that the design step of my project is complete.\
	Time spent: 3h06min\
	Activities: I spent much of my time ensuring I got every single measurement precisely by comparing to reference sizes I got through product listings, and compiling them onto a top view technical drawing. Additionally, I used this to begin designing rough mounting brackets I will need to align every part in the interferometer, by knowing where the screws will be. \
	
	Decisions\
	D-012: I decided to include both the screw adjustment system AND the micrometer in the mirror opposite to the diode. This is so I have a way to firmly adjust the mirror in case it is slightly off in terms of angle whilst keeping the precise translation that the micrometer head offers. I decided to put the head on a set of metal rods which act as rails, helping in stability to guide the mirror forward.\
	D-013: I decided to lengthen the supports for the magnetostriction mirror beyond the boundaries of the board. This is because the nickel rod is 20cm long, and therefore, keeping it stable along its length is crucial to mirror alignment.\

2026-08-11\
	Goal: Create a proper bill of materials, begin CAD designs for components of known dimension.\
	Time spent: 1h09min (44min logged on Stardance)\
	Activities: \
	Unexpected thing today - The ThorLABS aluminum UV protected mirrors' shipping failed, cancelling the purchase. (card from different country, exporting from Germany to Canada) and thus we were able to twitch to the silver mirror, which us shipping cost went back to normal for. Therefore, the transmitted power of the mirrors goes up from 82-83% to 95-97%! Parts remain unordered as of now, however.\
	
	Decisions\
	D-014: Switching to the silver version of the mirror \
	D-015:  Using paper as screen... grid paper is the best option. ELABORATE!! 
	
	Discuss alternatives thought up like MDF, cardboard, PVC etc.\
	D-016: CAD work will be done in Tinkercad's 3D modeling suite, as to make it easier and faster to block out ready-to-print designs than just about anywhere else, with good topology.

Traveling for a few days will make it difficult to journal in the coming days. However, I will try.

2026-08-12\
	Goal: Sort mirror situation\
	Time spent: 1h06min (N/A logging)
	Activities: Back and forth emails between us and customer service - search for alternative options.\
	Thorlabs mirrors ordered again, this time, the silver ones, and declined to ship once again - however, this time, it was the silver mirrors. The supplier said we needed to supply from Germany. However, the shipping cost from Germany amounted to 81.55 EUR (130.91$ CAD) which is higher than the cost of the mirrors themselves. While technically not in my budget costs, this would hurt my wallet quite a bit... therefore, I began my search for alternative mirror options. I primarily searched on Amazon, as this website offers a much more reliable shipping framework, making it easier to source. Instead of searching purely for optical grade mirrors, I expanded my search to anything which could fit the needs of a precision mirror.

---

| Product                                                                                                                                                                                                                                       | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | Cost (CAD)                           |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------ |
| **[Diameter 114 mm Focal Length 900mm Newtonian Reflector Mirror for Astronomical (D114F900JP)](https://www.amazon.ca/gp/product/B096F28YR6)**                                                                                                | 1/10λ rated surface accuracy and 92% reflectance @400-950nm. However. it is not a flat mirror (900mm focal length) and massive for my project, at 11.4 centimetres in diameter, which will make building mounts extremely tricky.                                                                                                                                                                                                                                                                                             | 71.48$                               |
| **[20mm Silicon(Si) Laser Reflection Mirrors for CO2 Laser Cutter Engraver/Cutting Engraving Machine, 3 Pcs Dia. 20mm /0.79"](https://www.amazon.ca/gp/product/B08R88TZMJ)**                                                                  | CO2 Laser Cutter Reflection Mirror. At 650nm, the listed uncertainty can be calculated to be about 0.77λ of surface flatness - this is because they are intended for 10.6 micrometer light, and work amazingly in this scenario, but not as much for shorter wavelengths such as the ones we are experimenting with. Other metal options are available but have higher uncertainties.                                                                                                                                         | 55.55$ (8.45$ as of 8/17/2026! wow!) |
| **[Alpha Nanotech Silica Wafers (Dry Oxide Only; Sizes: 6'', 4'', 2'', Oxide Thickness: 200 nm) (2 inches, Qty: 1 pc)](https://www.amazon.ca/gp/product/B07RFF6XWN)**                                                                         | This is not listed as a mirror, but rather, as a silica wafer. The imprecision translates to about 1/6λ at 650nm, which is great. However, 2 inches of diameter would still require slightly redesigning the mounts. Additionally, the reflectance, at 40%, is rather poor, and could prove to be even lower, meaning lots of power would be lost. This would mean adjusting to higher resistances in the TIA circuit to get the same outputs, which we would do by tuning speed of movement of the mirrors much more finely. | 45.00$                               |
| **[2PCS Small Size Front Surface Mirrors High Reflectivity for Projectors Scanners Precision Optical Instrument DIY Accessories(10x10mm,2mm)](https://www.amazon.ca/Reflectivity-Projectors-Precision-Instrument-Accessories/dp/B0GB9C66T6)** | First surface mirror which comes in a wide variety of sizes. 97% reflectance (at wavelength unknown) and lack of overall information. Arrives August 25-September 1st, which would absolutely NOT leave enough time to complete the project by September 1st. However, affordable.                                                                                                                                                                                                                                            | 24.65$                               |

``Decisions
`D-017: ended up **NOT** choosing any for now, as "I am still confident that the ThorLABS mirrors will arrive without too many issues." (Edit 08/17/2026: this aged well...) 
	The best backup option, as of now, is the Silica wafer, as it offers the level of precision I would need to perform magnetostriction experiments and is possible to use with more resistance in the TIA circuit. If not, looking back at the Edmunds mirrors and going ever so slightly overbudget doesn't seem like a bad option now...

2026-08-13\
	Goal: Confirm if ThorLABS mirrors are arriving...\
	Activities: Communication with mirror supplier.\
	Time spent: N/A\
	Today, we received a clarification email saying that shipping the silver mirrors from the US, rather than Germany, was possible. This would cut down costs from the aforementioned ridiculous European import price to the earlier US shipping value (equivalent to 49.40 CAD). We replied saying we would like this as an option - after some more payment difficulties, they invited us to directly call their support line. This will be a task for tommorow.\

2026-08-14\
	Goal: Confirm if ThorLABS mirrors are arriving...\
	Activities: Calling ThorLABS\
	Time spent: N/A\
	At last, it seemed there was a glimmer of hope for sourcing these high precision silver mirrors. When I called ThorLABS' service department, they told us the order had once again not been processed - we agreed to wire transfer directly. This is good, as it should solve issues regarding inconsistency with billing, shipping and card adresses, allowing for a smoother ordering experience for these mirrors.\

2026-08-15\
	Goal: Restart with project properly to prepare for building\
	Time spent: N/A\
	Activities: Unboxing all parts to ensure that they have properly arrived. \
	Today, I got home and all but four components were at my doorstep. I opened and checked every component to ensure the right materials had arrived. However, three of the items from Amazon had been cancelled. These were the **Lens** (**[DM-WJ002 185 Biological Microscope Objective Lens Silver 10X Achromatic Objectives Lens 160/0.17](https://www.amazon.ca/gp/product/B082P3P953)**), the **Nickel Rod ([SHONAN Nickel Anode- 7.87"x0.3"(Diameter) Nickle Anode, Pure Nickel Bar, Nickel Rod](https://www.amazon.ca/gp/product/B083LJWQYG))** and the **Beamsplitter ([Beam Splitter Cube, Optical Glass Dichroic Prism Ratio 50:50 Spectrome Sicence](https://www.amazon.ca/gp/product/B0B34FK2GF)**). I reordered these components to no issue. However, nothing more was heard of from the ThorLABS support team.
	this is where all the images go !!!!!

2026-08-16
	Activities: Disassembling DVD drive to procure laser diode, CAD design work for mounting system
	Time: 3h32min (2h09min recorded on Stardance)
	`Decisions\`
	`D-018: I will favor the usages of rounded, circular edges in my design. This is to reduce stress at corner points and save some material for the many different iterations which are likely to come.`
	`D-019: I enlarged the beam spliter design from 24x24mm in width to. This is to ensure the beam splitter remains solid. To make the component easier to print, I split it into two different pieces, which are designed to be firmly connected using two M3 screws.`
	`D-20: The laser diode mount will be designed slightly larger to encompass the metal casing it is placed within, as I am having trouble isolating it. This also required the center level of every other structural bracket to be raised to 22mm, as opposed to 12mm as previously.`

---
# CAD Design Process
2026-08-16\
1) **Micrometer Mirror Mount (MMM)**
I started by making the micrometer mount first. I largely based myself off the sized already present in my on-paper design initially. I measured some parts of my real micrometer head using a 30cm ruler, then, cross referenced it with blueprints of similar micrometer heads available on **[MiSUMi](https://us.misumi-ec.com/vona2/detail/223006520381/?seriesCode=223006520381&tab=catalog&Page=1)** (on this page.) The 1009-350 very closely matches the design I found on Amazon, so I used its exact measurements to my Tinkercad model off of. I believed by model was 5mm longer, so initially adjusted the design to this difference, however, upon looking back, it appears to be about the same length, too. This will be tested once component 3D printing begins. When making the supports, I stepped away from the original designs just a bit - instead of adding a second micrometer mounting I decided to only extend the top mounting downwards to support the micrometer, saving print material and improving stability of the micrometer. when making the mirror adjustment system, I decided o space the M3 screws further out than previously listed. While the mounting rods didn't directly have a specified spacing away from the screws, they now sit 35mm away from the central axis and 30mm above the ground. The mirror adjustment plates also did not have a specified length - they are now 90mm long (and 41mm tall.) The top micrometer mounting bracket plate is now 145.5mm instead of 145mm. I also added a support to the mirror adjustment plate to guide the mirror into the system.
![[Helios - MMM01.png|401]]-
Fig 1. - Tinkercad screenshot of micrometer and mirror 1 mounting systems as of 2026/08/17.
2) **Beamsplitter Mount (BSM)**
I had to go back to the drawing board when it comes to this mount. In my technical drawing, the 20x20mm beamsplitter would fit in a 24x24mm holder, meaning the outer walls were 4mm thick - there were also only two outer walls. In this iteration, I made the walls to be 7mm thick, giving a 34x34mm footprint. I also went back to the drawing board regarding the idea that this needed to be a single piece - Separating into two pieces, the beamsplitter bracket and beamsplitter mount, allows me to avoid complications with 90 degree upright angles while 3D printing, ensuring ease of production, while still being remaining to the original technical drawing model. I also added a circular 6mm radius to the outside of the M5 screws in the bracket, as this will slightly save on printing material while keeping the screws firmly guided, and the bracket firmly locked to the plate. I added two smaller 3mm holes to firmly lock the mount and bracket together, too, using either M3 screws or even wooden dowel pins.
![[Helios - BSM01.png]]
Fig 1. - Tinkercad screenshot of beamsplitter mounting system as of 2026/08/17.
3) **Diode Mount (LDM)**
Due to my previous efforts to isolate the laser diode from it's casing having failed yesterday, I decided to make a part which would incorporate the casing, too. Since the diode would therefore be raised 22mm up - higher than any other component - the standard for height required raising every other mounting platform to account for this difference. This mount is also slightly changed from its technical drawing, as the top-down footprint stayed about the same, but the way the laser diode is incorporated changed quite significantly. I make a hole in the bracket to serve as a guide for the metal component. To hold it in place more firmly, I added an M3 screw hole.
![[Helios - LDM01.png]]
Fig 1. - Tinkercad screenshot of diode mounting bracket as of 2026/08/17.
4) **Lens Mount (LMB)**
My lens has not actually arrived yet, therefore, I used Amazon size specifications and identified the lens to be a generic DM-WJ002 10X achromatic microscope objective. I searched online yet found no matching CAD model available. To approximate, I used the **[RMS10X10X Olympus Plan Achromat Objective, 0.25 NA, 10.6 mm WD](https://www.thorlabs.com/item/RMS10X)** STEP file from ThorLABS (granted, a much more expensive lens option) and converted it to a .obj file. Despite being broken, it was still meaningful insight on how to set up my actual lens. Eventually, a fixture system will be added, as I am reconsidering the M3 screw hole setup I have used in the diode mount. 
![[Helios - LMB01.png]]
Fig 1. - Tinkercad screenshot of lens mounting bracket as of 2026/08/17.

2026-08-17
	Goal: Finish CAD design elements.\
	Time spent: 2h23min (logged on Stardance)
	Activities: continuing CAD modeling, compiling and updating documentation from during and after the break\
	`Decisions`
	`D-021: I decided to keep the out of board bracket design in the solenoid brackets. This is as the nickel rod is very long, and needs to be adjusted to the center of mass to not cause any problems involving acoustic vibration.` 
	In the evening, we received an email from ThorLABS stating that the specific mirror I had purchased, the **[PFSQ05-03-P01](https://www.thorlabs.com/item/PFSQ05-03-P01)** was only in stock overseas. Disregarding the fact that it had not been listed as such in days past, I set out to once again review the list of mirror alternatives. As I did so, I spotted that the **[25mm Silicon(Si) Laser Reflection Mirrors for CO2 Laser Cutter Engraver/Cutting Engraving Machine, 3 Pcs Dia. 25mm /0.98"](https://www.amazon.ca/gp/product/B08R88VRW1)** were set at an 85% discount, and were now selling for 8.45$. I, therefore, rushed to order a set of these mirrors as a backup option, in case the ThorLABS mirrors ended up not arriving. These mirrors, at 650nm, have about a 0.77 λ surface flatness. While not being exactly designed for the wavelengths I need (CO2 laser cutters use wavelengths of about 10.6 micrometers), it was way too good of a deal to simply pass up. These are set to ship on 2026-08-19.

---

# CAD Design (contd.)

5) **Solenoid Mirror Mount (SMM)**
This is possibly the most complex part of the entire mounting system. I began by modeling the solenoid cover around a to-scale nickel rod - since this item hasn't arrived yet, I can't measure true scale, so I had to use Amazon listing measurements as a reference. This component is likely the most unchanged aspect of the technical drawing. I then built two, smaller separated support brackets as opposed to what is illustrated in the technical drawing -  this is to ensure the solenoid cover and over components remain leveled with respect to the center of mass of the overall system (solenoid, cover, nickel rod, mirror mounting plates). Center of mass is a concept which I had to heavily explore through this system. A balanced center of mass keeps the system from tipping in any way while dampening any surrounding acoustic vibration, keeping everything firmly in place. Therefore, I explored several different mirror mounting designs.\
![[Helios - SMM01.png]]
This was the first iteration - a rod rail system with guides in the mount and brackets which would force translation forward. The problem is that the adjustment screws would throw the plates off course in rather difficult to predict ways, and the friction between the PETG-CF and material used for the rails would lead to the uneven surfaces of both materials throwing the mirror off course ever so slightly. When measuring micrometers of change, this is not ideal for measuring the effects of magnetostriction.\
![[Helios - SMM02.png]]
This was the second iteration - a non-adjustable mirror mount with a hole fitting neatly with the nickel rod, and another to place the mirror in. This was deemed to not be adjustable enough, as, even with the lack of friction, the inability to adjust the rotation of the mirror precisely was still a major downside. Then, for my third iteration, I envisioned simply gluing the mirror itself to the nickel rod. This was a better idea than the non adjustable mirror mount, saving a few grams, yet it was still not fully optimal.\
![[Helios - SMM03.png]]
Here is the iteration i ended up deciding on. I re-introduced the mirror mounting plates, this time, suspended in the air, and cut off a small section of the top to save on material - while incorporating the nickel rod hole from the previous design. This gives the best of both worlds when it comes to stability and adjustability. I decided to add a fictional counterbalance, whose volume will be determined once the mirror mounting system has been properly measured. 
A way to link the adjustment brackets together would now be great., as the taller one is currently hanging, and the rest of the overall system is very sensitive to changes.

2026-08-18
	Goal: Catch up on documentation, try out 3dprinting and Arduino starter kit functionality.
	Time spent: 3h05min (2h32min logged on Stardance)
	Activities: Sorting out mirrors, successful experiment with Uno R3 kit and DVD drive laser diode, catching up fully on documentation.
	Today, we were able to call ThorLABS about the mirrors. The payment had gone through, yet, the lead time for importing the **[PFSQ05-03-P01](https://www.thorlabs.com/item/PFSQ05-03-P01)** would about 3 months, which is far too long for my project's needs. Therefore, I considered to change the order to the **[PFSQ05-03-G01](https://www.thorlabs.com/item/PFSQ05-03-G01)** , which has the same dimensions yet is coated with aluminum and performs similarly. However, this item costs more, and therefore needed another wire transfer - increasing shipping time by a matter of 5 days on top of the week expected for international shipping, which would be about August 30th. 2 days of room to work with is still far too few, so I decided that I had to switch to a product of equal or lower price. I considered the **[PFSQ05-03-M03](https://www.thorlabs.com/item/PFSQ05-03-M03)** for its equal price and gold coating. It is technically not meant for the wavelengths I need yet is shown to have 95.71% reflectance (within range of P-01 silver's 95.72%). Finally, I decided on the **[PF05-03-P01](https://www.thorlabs.com/item/PF05-03-P01)** as it is another silver mirror which would perform identically to its former square silver twin which is unavailable in the North American market. It is also of the same dimensions, yet instead, it is cylindrical, meaning I would need to slightly rework the mounts - this however costs 5.70 USD less. It is arriving August 25th. All things considered, this mirror seems like a solid purchase!\
	Upon opening the Elegoo R3 kit, I found that the resistors were already labeled from 100 to 1M Ohm. This is a pleasant surprise, as an amazon review claimed the product had less than what was advertised - it in fact had more.
	I then further disassembled the DVD drive down to the raw laser diode, and got the Arduino to successfully power the laser diode! Great news with just a small problem - now, the collimating lens was detached, so the light expands, fast! This means I need to either re-align the DVD drive lens or restructure the design to use the 10X lens to collimate the beam of light, which would be tricky to do precisely. Nevertheless, I'm extremely happy the electronics now work! The CAD for the laser diode will need a redesign, but everything seems to be falling into place rather smoothly, for now. My goal tomorrow is to have a working full design I can submit for a funding request.


# **Sources for this document 
(bibliography.md file to be created later)**
[1]

“Magnetostriction with the Michelson interferometer,” Accessed: Aug. 02, 2026. [Online]. Available: https://phywe-itemservice.s3.eu-central-1.amazonaws.com/sites/DMS-Phywe/PROD/de-DE/item/phy_itemtestinstruction/P2/P2430811/P2430810_en.pdf

[2]

“Beamsplitters Selection Guide For Optical Applications | Optometrics,” _Omega Optical_, Aug. 04, 2020. https://omega-optical.com/blog/beamsplitters-guide/ (accessed Aug. 08, 2026).

[3]

“Michelson Interferometer Lab Setup: Assembly and Alignment Guide,” _Edmundo ptics.com_, 2023. https://www.edmundoptics.com/knowledge-center/application-notes/optics/michelson-interferometer-lab-setup/?srsltid=afmbooqn2c4oqh7aiwxtvhnmm83wpudjhrfnunszm2f-co2m8ysokhul (accessed July 23, 2026).

[4]

“Michelson-Interferometer – Stoppi,” _Stoppi-homemade-physics.de_, 2026. https://stoppi-homemade-physics.de/michelson-interferometer/ (accessed July 23, 2026).

[5]

“BPW34 Photodiode Tutorial: Fast Light Sensing, Transimpedance Amplifiers (TIA), Arduino/ESP32 Interfaces, Ambient-Light Rejection, and Precision Optical Projects,” _Leobot Electronics_, 2019. https://leobot.net/tutorial/1116?srsltid=afmbooopagnvg12vstq3dtvbttizcvafkiru9jjx0otks_olei1qqyu_ (accessed July 26, 2026).

[6]

Khaled Magdy, “Arduino Photodiode Light Sensor (BPW34) Circuit & Code Example,” Jan. 2024. Accessed: July 27, 2026. [Online]. Available: https://deepbluembedded.com/arduino-photodiode-light-sensor-bpw34-circuit-code-example/

[7]

Jason, “UA741 Operational Amplifier: Exploring Its Key Features and Practical Applications,” 2025. Accessed: July 28, 2026. [Online]. Available: https://www.ic-components.com/blog/ua741-operational-amplifier-exploring-its-key-features-and-practical-applications.jsp

[8]

ibid, 1.

[9] 

ibid, 2.

[10]

ibid, 4.

[11]

D. E. Vasquez, “Young’s Double-Slit Experiment Explained Explained,” Mar. 2026. Accessed: Aug. 08, 2026. [Online]. Available: https://physicsfundamentals.org/blog/youngs-double-slit-experiment
