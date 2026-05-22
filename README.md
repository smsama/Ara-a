El proyecto usa 8 servos controlados por un ESP32 para mover una "araña" de cuatro patas. 
Precaución: es muy importanto poner los servos a 90° antes de ensamblar la araña. Además, los servos deben quedar "mirando hacia abajo" perpendicularmente al piso. 
Para poner los servos a 90° usar el código "SETEAR_SERVOS" o crear un código que los ponga a 90°. NO PONER LOS SERVOS A 90° HACIENDO FUERZA
Chequear los pines a los que están conectados los servos, cada pata tiene dos servos. Uno de los servos (UP) "levanta" la pata que se va a mover, y el otro la desplaza (MOV). 
Esquema de distribución de las patas:

    FRONT_IZQ -------------------- FRONT_DER
        |                              |
        |                              |
        |                              |
        |                              |
        |                              |
        |                              |
    BACK_IZQ ---------------------- BACK_DER
    
Importante: al conectar los servos verificar que los cables no queden tirantes (para que las patas se puedan mover), y que no toquen el piso. 
El código usa la librería ESP32_Servo, que está subida entre los archivos.
