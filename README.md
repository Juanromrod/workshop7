# Workshop 7: I2C y ThingSpeak
- La finalidad de este taller fue diseñar una solución IoT para la monitorización de temperatura, se utilizaron 2 arduinos, un led, una proto board y un sensor de temperatura LM35. Además del uso de la plataforma ThingSpeak para intentar una conexión inalámbrica para la visualización de los datos en un dashboard. A si mismo, en caso de que la temperatura sobrepasara los 30 grados centigrados, se enciende un led que indica una alta temperatura.

# Funcionamiento
- Se partió de la configuración I2C (Master-Slave) para la lectura de datos del sensor y envio a ThingSpeak. Para esto, se definió un arduino (Esclavo), el cual lee los datos de temperatura del sensor por la entrada analógica, hace la conversión a grados celsius y la envía al otro arduino (Maestro), el cuál se encarga de la comunicación con la plataforma ThingSpeak y mediante un canal muestra los datos en tiempo real en un dashboard junto con un historico de los valores leidos por el sensor. (Debido a que el arduino no cuenta con un módulo de WIFI se realizó un script en python para la comunicación con ThingSpeak)

# Diagramas de actividad adjuntos
- Desarrollo de workshop: Metodología general que utilizamos para la realización del taller
- Desarrollo del sistema: Funcionamiento explicado de la comunicación I2C con los arduinos

# Código y documentación
- En el repositorio se encuentran los respectivos códigos de cada arduino el Maestro y el Esclavo, los cuales son los archivos .ino y el script de python utilizado para el intento de conexión con ThingSpeak .py

# Referencias
Las siguientes referencias se utilizaron para entender el funcionamiento de la conexión I2C y en general para los requerimientos de conexiones, drivers y código necesario para el desarrollo del workshop, a su vez se hizo uso de la herramienta ChatGPT para facilitar el desarrollo de código de los programas.
- https://www.youtube.com/watch?v=az-X_1QSuOY
- https://docs.arduino.cc/learn/communication/wire
- https://bc-robotics.com/tutorials/using-a-tmp36-temperature-sensor-with-arduino/
- https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
