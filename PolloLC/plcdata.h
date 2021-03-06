#ifndef PLCDATA_H
#define PLCDATA_H

#include <snap7.h>
#include <map>
#include <QTimer>
#include <functional>

class PLCData : public QObject {
    Q_OBJECT

public:
    PLCData();
    ~PLCData();
    bool getBoolAt(byte position);
    short getNumberAt(byte position);
    void writeBoolAt(byte position, bool value);
    void writeNumberAt(byte position, short value);
    void decrementNumberAt(byte position);
    void updateBoxLocation(short position);
    void addOnRefreshCallback(std::function<void(void)> _onRefresh);


    //Tiempos en ms
    static const int TSensorMuelle = 750;
    static const int TSensorCinta = 750;
    static const int TCinta0 = 500;
    static const int TCintas = 1500;
    static const int TSalidaCilindro = 500;
    static const int TRecogerCilindro = 500;
    static const int TCaidaCaja = 750;

    //Capacidad en unidades
    static const short CapacidadMuelle = 25;

    //Tiempo entre actualizaciones de memoria en ms
    static const int TEntreLecturas = 100;

private:
    //Cliente s7
    S7Object client;
    const char* PLC_IP = "172.18.67.99";

    //Diccionarios para almacenamiento de datos
    std::map<byte, bool> plc_bool;
    std::map<byte, short> plc_number;

    //Timer para desencadenar la lectura
    QTimer* lecturaTimer;

    //Callback a ejecutar cuando se terminan de actualizar los datos
    std::vector<std::function<void(void)>> onRefresh;

private:
    void setPLCInitState(void);
    inline void writeNumber(byte* container, int number, int offset);
    inline void writeNumber(byte* container, short number, int offset);
    inline void writeBit(int srcbyte, int bit, bool data);
    inline short readShort(byte* container, int start_index);
    inline bool readBit(byte* data, int byte_index, int bit_number);
    inline void swapShort(byte* data, int start_index);
    inline void swapInt(byte* data, int start_index);

private slots:
    void updatePLCState(void);

};

#endif // PLCDATA_H
