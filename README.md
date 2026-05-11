# SpotifyDisplay
## What is this project?
This is a recreation of the overpriced Spotify display, and it has features for YouTube Music and locally stored songs.
## Why did I make this project?
The original is too expensive, and this is a very fun project.

## Pictures!
### Zine - 

<img width="1688" height="2588" alt="SpotifyDisplay (1)" src="https://github.com/user-attachments/assets/734c141c-7e0c-4ed9-8c37-ff012cdb869a" />


### The Code - 
The connection between the ESP32 and the PC, and the programming for the ESP32.

<img width="1919" height="1079" alt="Screenshot 2026-04-15 215934" src="https://github.com/user-attachments/assets/aa862642-12f3-463d-a0c4-76bfa6fc1219" />
<img width="1919" height="1079" alt="Screenshot 2026-04-15 215938" src="https://github.com/user-attachments/assets/53dd8fb3-cbec-4f95-b347-1376139097c7" />

### The CAD - 

<img width="1919" height="1078" alt="Screenshot 2026-04-30 104950" src="https://github.com/user-attachments/assets/3f708f68-7e1f-4175-9d9d-8ce4475c956d" />
<img width="939" height="636" alt="Screenshot 2026-04-30 105559" src="https://github.com/user-attachments/assets/68b331fb-4004-47f1-bab8-49f42fb98899" />

### The Wiring Diagram - 

<img width="1425" height="806" alt="WiringDiagram" src="https://github.com/user-attachments/assets/f93078cc-a7a3-4d6f-9e4c-01bbece0686c" />


## Bill of Materials (BOM)
| Name | Purpose | Quantity | Total Cost (USD) | Link | Distributor |
|------|---------|----------|------------------|------|-------------|
| KY-040 Rotary Encoder Module | 	The Volume control. |	1	| $2.00	| [View Product](https://www.amazon.in/Electronic-Spices-KY-040-encoder-development/dp/B0BHWCWJDR?source=ps-sl-shoppingads-lpcontext&ref_=fplfs&psc=1&smid=AJ6SIZC8YQDZX) | Amazon |
| M3x4 mm Brass Heat Set Threaded Round Insert Nut (25Pcs) | Metal screw threads to hold the plastic | 1 | 4.00 | [View Product](https://robu.in/product/m3-x-4-mm-brass-heat-set-knurl-threaded-round-insert-nut-25-pcs/) | Robu |
| Cherry MX RGB Switch | Provides user input by completing a connection while pressed | 1 | 5.00 | [View Product](https://meckeys.com/shop/accessories/keyboard-accessories/key-switches/cherry-mx-rgb-switch/?attribute_pa_cherry-mx=black-rgb) | Meckeys |
| Blue 1.8 Inch ST7735 TFT LCD Module (128×160) | Display for current track and UI elements | 1 | 5.00 | [View Product](https://robu.in/product/blue-1-8-inch-st7735-tft-lcd-module-with-4-io-128160/) | Robu |
| 7Semi ESP32-S3-Dev-BoardC-1-N4R2 | Core computation, handles images and acts as WiFi bridge | 1 | 11.80 | [View Product](https://7semi.com/esp32-s3-dev-board-wifi-bluetooth-dualusb/) | 7Semi |

## How to Build
 
### 1. 3D Print the Case
- Open `case.f3d` or `lid.f3d` in Autodesk Fusion 360, or use the `case.step` files in any CAD software/slicer directly.
- Print the case and lid in your filament of choice (PLA works fine). The design has cutouts for the ST7735 display, the Cherry MX switch, and the rotary encoder.
- Once printed, press the M3x4mm brass heat-set inserts into the screw holes on the case using a soldering iron. This gives you durable metal threads so the lid can be screwed on and off without stripping the plastic.
### 2. Assemble the PCB
- The KiCad project files (`SpotifyPCB.kicad_pcb`, `.kicad_sch`, `.kicad_pro`, `.kicad_prl`) contain the full schematic and PCB layout.
- Refer to the **Wiring Diagram** above and the schematic for exact pin connections.
### 3. Flash the ESP32
 
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and add ESP32 board support (Boards Manager).
2. Install the TFT_eSPI library via the Library Manager.
3. Open `esp32spotify.cpp` and edit the following lines with your own details:
   ```cpp
   const char* ssid = "YOUR_WIFI";
   const char* password = "YOUR_PASSWORD";
   const char* pcIP = "192.168.1.47";     
   ```
4. Select your board (`ESP32S3 Dev Module`) and then upload with the right COM port.

### 4. Set Up the PC Server
 
The Python script `pc_connect.py` runs a small Flask server on your PC that listens for commands from the ESP32 and translates them into media key presses.
 
1. Install Python.
2. Install Python dependencies:
   ```bash
   pip install flask pyautogui
   ```
3. Run the script:
   ```bash
   python pc_connect.py
   ```
   The server runs on port `5000` and connects from any device on your local network.
 
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
