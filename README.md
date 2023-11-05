# Workshop 7: I2C y ThingSpeak
La finalidad de este taller fue diseñar una solución IoT para el control de temperatura, se utilizaron 2 arduinos, un led, una proto board y un sensor de temperatura LM35. Además del uso de la plataforma ThingSpeak para intentar una conexión inalámbrica.

# Funcionamiento

- Se partió de la configuración I2C (Master-Slave) para la lectura de datos del sensor y envio a ThingSpeak. Para esto, se definió un arduino (Esclavo), el cual lee los datos de temperatura del sensor por la entrada analógica, hace la conversión a grados celsius y la envía al otro arduino (Maestro)

# Diagramas de actividad adjuntos
-Desarrollo de workshop: Metodología general que utilizamos para la realización del taller
-Desarrollo del sistema: Funcionamiento explicado del sistema de I2C con los arduinos