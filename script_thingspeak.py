import serial
import requests

Configura la comunicación serial (ajusta el puerto y la velocidad según tu configuración)
arduino_port = 'COM6'  # Ejemplo de puerto en sistemas Linux, ajusta el puerto en Windows
baud_rate = 9600

Configura tu clave de escritura de ThingSpeak
thing_speak_api_key = 'U5ENPROZ8FZ6I158'

URL de ThingSpeak para enviar datos
thing_speak_url = f'https://api.thingspeak.com/update?api_key={thing_speak_api_key}'

try:
    arduino = serial.Serial(arduino_port, baud_rate)
    print(f"Conectado a {arduino_port} a {baud_rate} baud")

    while True:
        data = arduino.readline().decode().strip()
        print(f'Datos leídos desde Arduino: {data}')

        # Envía los datos a ThingSpeak
        try:
            response = requests.get(thing_speak_url, params={'field1': data})
            if response.status_code == 200:
                print('Datos enviados a ThingSpeak exitosamente')
            else:
                print('Error al enviar datos a ThingSpeak')
        except requests.exceptions.RequestException as e:
            print(f'Error en la solicitud HTTP a ThingSpeak: {e}')

except serial.SerialException as e:
    print(f'Error al abrir el puerto serie: {e}')
except KeyboardInterrupt:
    print('Script finalizado por el usuario')

finally:
    if 'arduino' in locals():
        arduino.close()
﻿
HRuss14
hruss14
