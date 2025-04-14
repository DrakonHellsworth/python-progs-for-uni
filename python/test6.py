import pywhatkit as pwk
import pyautogui
import time

pn = "+919027233941"  # Recipient number
mssg = "This is what you wanted, right? Fak u"

n = 5  # Number of times to send the message

for i in range(n):
    pwk.sendwhatmsg_instantly(pn, mssg, wait_time=10, tab_close=True)
    time.sleep(12)  # Wait for WhatsApp Web to load
    pyautogui.press("enter")  # Press Enter to send
    time.sleep(5)  # Wait before sending next message

print("Message sent successfully")