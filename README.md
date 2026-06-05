# SpotifyDisplay
## What is this project?
This is a recreation of the overpriced Spotify display, and it has features for YouTube Music and locally stored songs. It is made using the ESP32-S3-Dev-BoardC-1-N4R2 for complete control of display, inputs, and Wi-Fi communication, connecting all the parts for them to function. The Display has three programmable buttons. I will be using them for Previous, Pause/Play, and Next. It also has a KY-040 Rotary Encoder Module, which is used for volume up and down. The display is going to be a 1.8" ST7735 TFT LCD Module (128×160 resolution).
## Why did I make this project?
The original is too expensive, it ranges from 73.04 to 250 dollars. This is a much better version, which would cost only 27.8 dollars to make on your own. It is a very simple, reproducible project. It is also a very cool project; this project can also control your local and YouTube music. Very, very cool project to make!

## Pictures!
### Zine - 

<img width="1688" height="2588" alt="SpotifyDisplay (1)" src="https://github.com/user-attachments/assets/734c141c-7e0c-4ed9-8c37-ff012cdb869a" />


### The Code - 
The connection between the ESP32 and the PC, and the programming for the ESP32.

<img width="1919" height="1079" alt="Screenshot 2026-04-15 215934" src="https://github.com/user-attachments/assets/aa862642-12f3-463d-a0c4-76bfa6fc1219" />
<img width="1919" height="1079" alt="Screenshot 2026-04-15 215938" src="https://github.com/user-attachments/assets/53dd8fb3-cbec-4f95-b347-1376139097c7" />

### The CAD - 

<img width="1420" height="632" alt="Print" src="https://github.com/user-attachments/assets/d8d2c328-65bd-467a-a508-0476a27bb1fb" />

<img width="620" height="299" alt="image" src="https://github.com/user-attachments/assets/9f944572-5289-4572-ace8-a4e02172f9fe" />
**Parts stuck using an adhesive-neodymium magnet.**
### The Wiring Diagram - 

<img width="1425" height="806" alt="WiringDiagram" src="https://github.com/user-attachments/assets/f93078cc-a7a3-4d6f-9e4c-01bbece0686c" />


## Bill of Materials (BOM)
| Name | Purpose | Quantity | Total Cost (USD) | Link | Distributor |
|------|---------|----------|------------------|------|-------------|
| KY-040 Rotary Encoder Module | The Volume control. | 1 | $2.00 | [View Product](https://www.amazon.in/Electronic-Spices-KY-040-encoder-development/dp/B0BHWCWJDR?source=ps-sl-shoppingads-lpcontext&ref_=fplfs&psc=1&smid=AJ6SIZC8YQDZX) | Amazon |
| M3x4 mm Brass Heat Set Threaded Round Insert Nut (25Pcs) | Metal screw threads to hold the plastic | 1 Pack | $4.00 | [View Product](https://robu.in/product/m3-x-4-mm-brass-heat-set-knurl-threaded-round-insert-nut-25-pcs/) | Robu |
| M2x18 mm Brass Screws | Metal screw threads of M2 dia to hold the plastic | 1 Pack | $15.00 | [View Product](https://www.desertcart.in/products/839152070-m-meterxity-20-pack-wood-screws-m2-x-18mm-brass) | Desertcart |
| Cherry MX RGB Switch | Provides user input by completing a connection while pressed | 10 (Minimum) | $5.00 | [View Product](https://meckeys.com/shop/accessories/keyboard-accessories/key-switches/cherry-mx-rgb-switch/?attribute_pa_cherry-mx=black-rgb) | Meckeys |
| M2x18 mm Brass Nut | Metal nut of M2 dia | 1 Pack | $1.00 | [View Product](https://www.amazon.in/M2-Nut-Threaded-Hex-2mm/dp/B09YRXHYGH) | Amazon |
| Blue 1.8 Inch ST7735 TFT LCD Module (128×160) | Display for current track and UI elements | 1 | $5.00 | [View Product](https://robu.in/product/blue-1-8-inch-st7735-tft-lcd-module-with-4-io-128160/) | Robu |
| 7Semi ESP32-S3-Dev-BoardC-1-N4R2 | Core computation, handles images and acts as WiFi bridge | 1 | $11.80 | [View Product](https://7semi.com/esp32-s3-dev-board-wifi-bluetooth-dualusb/) | 7Semi |
| 4mm Diameter Neodymium Disc Magnets | Lid to Case attachment (use glue if no adhesive side) | 10 | $0.5 | [View Product](https://onlyscrews.in/products/4mm-diameter-neodymium-disc-magnets-n35) | OnlyScrews |
| **Total** |  |  | **$44.30** |  |  |

## How to Build
 
### 1. 3D Print the Case
- Open case.f3d or lid.f3d in Autodesk Fusion 360, or use the case.step files in any CAD software/slicer directly.
- Print the case and lid in your filament of choice (PLA works fine). The design has cutouts for the ST7735 display, the Cherry MX switch, and the rotary encoder.
- Once printed, press the M3x4mm brass heat-set inserts into the screw holes on the case using a soldering iron. This gives you durable metal threads so the lid can be screwed on and off without stripping the plastic.
- **Any parts that are floating should be stuck using a neodymium magnet.**
### 2. Assemble the PCB
- The KiCad project files (SpotifyPCB.kicad_pcb, .kicad_sch, .kicad_pro, .kicad_prl) contain the full schematic and PCB layout.
- Refer to the **Wiring Diagram** above and the schematic for exact pin connections.
### 3. Flash the ESP32
 
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and add ESP32 board support (Boards Manager).
2. Install the TFT_eSPI library via the Library Manager.
3. Open esp32spotify.cpp and edit the following lines with your own details:
   ```cpp
   const char* ssid = "YOUR_WIFI";
   const char* password = "YOUR_PASSWORD";
   const char* pcIP = "192.168.1.47";     
   ```
4. Select your board ESP32S3 Dev Module and then upload with the right COM port.

### 4. Set Up the PC Server
 
The Python script pc_connect.py runs a small Flask server on your PC that listens for commands from the ESP32 and translates them into media key presses.
 
1. Install Python.
2. Install Python dependencies: pip install flask pyautogui
3. Run the script: python pc_connect.py
   The server runs on port 5000 and connects from any device on your local network.
---
 
## How to Use
 
Once everything is assembled and both the ESP32 and PC server are running:
 
| Control | Action |
|---------|--------|
| **Next Button** (GPIO12) | Skip to next track |
| **Prev Button** (GPIO13) | Go to previous track |
| **Play Button** (GPIO14) | Play / Pause |
| **Rotate Encoder clockwise** | Volume Up |
| **Rotate Encoder counter-clockwise** | Volume Down |
| **Press Encoder** (SW) | Play / Pause (same as Play button) |
 
The display shows the current track info fetched in real time over WiFi. It works with **Spotify**, **YouTube Music**, and **locally stored songs** — anything that responds to system media keys on your PC.
