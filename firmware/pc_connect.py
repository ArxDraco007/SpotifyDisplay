from flask import Flask
import pyautogui

app = Flask(__name__)

@app.route('/')
def home():
    return "Server running"

@app.route('/next')
def next_track():
    pyautogui.press('nexttrack')
    return "Next"

@app.route('/prev')
def prev_track():
    pyautogui.press('prevtrack')
    return "Previous"

@app.route('/play')
def play_pause():
    pyautogui.press('playpause')
    return "Play/Pause"

# 🔊 NEW
@app.route('/S')
def vol_up():
    pyautogui.press('volumeup')
    return "Volume Up"

@app.route('/voldown')
def vol_down():
    pyautogui.press('volumedown')
    return "Volume Down"

app.run(host='0.0.0.0', port=5000)
