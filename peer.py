import socket

print("starting connect")

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(5)  # timeout 5 giây

try:
    s.connect(("127.0.0.1", 6881))  # IP public của máy host
    print("connected!")
except socket.timeout:
    print("Connection timed out")
except Exception as e:
    print("Connection failed:", e)
