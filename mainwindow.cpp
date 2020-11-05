#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , plcd(new PLCData())
    , updateTimer(new QTimer(this))
{
    ui->setupUi(this);

    //client = Cli_Create();
    //Cli_ConnectTo(client, "172.18.67.99", 0, 0);
    //this->setPLCInitState();

    connect(this->ui->knownLocationButton, SIGNAL(pressed()), this, SLOT(knownLocationOnClick()));
    connect(this->ui->acceptNextM1, SIGNAL(pressed()), this, SLOT(acceptNextM1OnClick()));
    connect(this->ui->acceptNextM2, SIGNAL(pressed()), this, SLOT(acceptNextM2OnClick()));
    connect(this->ui->acceptNextM3, SIGNAL(pressed()), this, SLOT(acceptNextM3OnClick()));
    connect(this->ui->decrementM1, SIGNAL(pressed()), this, SLOT(decrementM1OnClick()));
    connect(this->ui->decrementM2, SIGNAL(pressed()), this, SLOT(decrementM2OnClick()));
    connect(this->ui->decrementM3, SIGNAL(pressed()), this, SLOT(decrementM3OnClick()));
    connect(this->ui->decrementMD, SIGNAL(pressed()), this, SLOT(decrementMDOnClick()));
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updatePLCState()));
    updateTimer->start(this->updateRate);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::writeBit(int srcbyte, int bit, bool on) {
//    Cli_WriteArea(client, (int)S7AreaMK, 0, 8*srcbyte + bit, 1, S7WLBit, &on);
//}

//TODO: Escribir bit a bit xq sino estamos petando lo que pueda haber en las otras
void MainWindow::knownLocationOnClick(void) { plcd->writeBoolAt(28, true); }
void MainWindow::acceptNextM1OnClick(void) { plcd->writeBoolAt(25, true); }
void MainWindow::acceptNextM2OnClick(void) { plcd->writeBoolAt(26, true); }
void MainWindow::acceptNextM3OnClick(void) { plcd->writeBoolAt(27, true); }
void MainWindow::decrementM1OnClick(void) { plcd->decrementNumberAt(0); }
void MainWindow::decrementM2OnClick(void) { plcd->decrementNumberAt(1); }
void MainWindow::decrementM3OnClick(void) { plcd->decrementNumberAt(2); }
void MainWindow::decrementMDOnClick(void) { plcd->decrementNumberAt(3); }


//void MainWindow::setPLCInitState(void) {
//    byte* initData = new byte[50];
//    //Hacemos reset de todas las variables
//    for (int i = 0; i < 50; i++) initData[i] = 0x00;

//    //Sensores -> a 0 -> Nothing to do
//    //Cilindros -> todo a 0 menos el flag de esta dentro
//    //  Estos flags estan en 2.1, 2.2, 2.3
//    initData[2] = (0x00 | bitmap.at(1) | bitmap.at(2) | bitmap.at(3));

//    //Motores -> a 0 -> Nothing to do
//    //Aceptar cajas -> a 0 -> Nothing to do
//    //Muelles llenos -> a 0 -> Nothing to do
//    //Contador de cajas por muelle -> a 0 -> Nothing to do
//    //Capacidad de los muelles
//    writeNumber(initData, this->CapacidadMuelle, 16);

//    //Tiempos que tardan las cajas en pasar por los sensores
//    //  Tiempos de los muelles
//    writeNumber(initData, this->TPasarPorSensorMuelle, 18);
//    //  Tiempos de las cintas
//    writeNumber(initData, this->TPasarPorSensorCinta, 22);
//    //  Tiempo en cinta 0
//    writeNumber(initData, this->TCinta0, 26);
//    //  Tiempo en cintas largas
//    writeNumber(initData, this->TCinta0, 30);

//    //Tiempos de los cilindros
//    //  Tiempo en salir
//    writeNumber(initData, this->TiempoSalidaCilindro, 34);
//    //  Tiempo en volver
//    writeNumber(initData, this->TiempoRecogerCilindro, 38);

//    //Tiempo caida de cajas
//    writeNumber(initData, this->TiempoCaidaCaja, 42);

//    Cli_MBWrite(client, 0, 50, initData);
//}

//bool MainWindow::readBit(byte* data, int byte_index, int bit_number) {
//    return (data[byte_index] & bitmap.at(bit_number)) == bitmap.at(bit_number);
//}

//inline void MainWindow::writeNumber(byte* container, int number, int offset) {
//    memcpy(container + offset, &number, sizeof(int));
//    swapInt(container, offset);
//}
//inline void MainWindow::writeNumber(byte* container, short number, int offset) {
//    memcpy(container + offset, &number, sizeof(short));
//    swapShort(container, offset);
//}

//inline short MainWindow::readShort(byte* container, int start_index) {
//    short value;
//    swapShort(container, start_index);
//    memcpy(&value, container + start_index, sizeof(short));
//    return value;
//}

//inline void MainWindow::swapShort(byte* data, int start_index) {
//    byte tmp = data[start_index];
//    data[start_index] = data[start_index + 1];
//    data[start_index + 1] = tmp;
//}

//inline void MainWindow::swapInt(byte* data, int start_index) {
//    byte tmp = data[start_index];
//    data[start_index] = data[start_index + 3];
//    data[start_index + 3] = tmp;

//    tmp = data[start_index + 1];
//    data[start_index + 1] = data[start_index + 2];
//    data[start_index + 2] = tmp;
//}

void MainWindow::updatePLCState(void) {
//    byte* read_data = new byte[15];
//    Cli_MBRead(client, 0, 15, read_data);

//    this->ui->S0->setStyleSheet(readBit(read_data, 0, 0) ? GLED_ON : GLED_OFF);
//    this->ui->S1cinta->setStyleSheet(readBit(read_data, 0, 1) ? GLED_ON : GLED_OFF);
//    this->ui->S2cinta->setStyleSheet(readBit(read_data, 0, 2) ? GLED_ON : GLED_OFF);
//    this->ui->S3cinta->setStyleSheet(readBit(read_data, 0, 3) ? GLED_ON : GLED_OFF);
//    this->ui->S1buffer->setStyleSheet(readBit(read_data, 0, 4) ? GLED_ON : GLED_OFF);
//    this->ui->S2buffer->setStyleSheet(readBit(read_data, 0, 5) ? GLED_ON : GLED_OFF);
//    this->ui->S3buffer->setStyleSheet(readBit(read_data, 0, 6) ? GLED_ON : GLED_OFF);
//    this->ui->SDbuffer->setStyleSheet(readBit(read_data, 0, 7) ? GLED_ON : GLED_OFF);

//    this->ui->C1e->setStyleSheet(readBit(read_data, 1, 0) ? GLED_ON : GLED_OFF);
//    this->ui->C2e->setStyleSheet(readBit(read_data, 1, 1) ? GLED_ON : GLED_OFF);
//    this->ui->C3e->setStyleSheet(readBit(read_data, 1, 2) ? GLED_ON : GLED_OFF);
//    this->ui->C1r->setStyleSheet(readBit(read_data, 1, 3) ? GLED_ON : GLED_OFF);
//    this->ui->C2r->setStyleSheet(readBit(read_data, 1, 4) ? GLED_ON : GLED_OFF);
//    this->ui->C3r->setStyleSheet(readBit(read_data, 1, 5) ? GLED_ON : GLED_OFF);
//    this->ui->C1f->setStyleSheet(readBit(read_data, 1, 6) ? GLED_ON : GLED_OFF);
//    this->ui->C2f->setStyleSheet(readBit(read_data, 1, 7) ? GLED_ON : GLED_OFF);
//    this->ui->C3f->setStyleSheet(readBit(read_data, 2, 0) ? GLED_ON : GLED_OFF);
//    this->ui->C1d->setStyleSheet(readBit(read_data, 2, 1) ? GLED_ON : GLED_OFF);
//    this->ui->C2d->setStyleSheet(readBit(read_data, 2, 2) ? GLED_ON : GLED_OFF);
//    this->ui->C3d->setStyleSheet(readBit(read_data, 2, 3) ? GLED_ON : GLED_OFF);

//    this->ui->M0->setStyleSheet(readBit(read_data, 3, 0) ? GLED_ON : GLED_OFF);
//    this->ui->M1->setStyleSheet(readBit(read_data, 3, 1) ? GLED_ON : GLED_OFF);
//    this->ui->M2->setStyleSheet(readBit(read_data, 3, 2) ? GLED_ON : GLED_OFF);
//    this->ui->M3->setStyleSheet(readBit(read_data, 3, 3) ? GLED_ON : GLED_OFF);
//    this->ui->M4->setStyleSheet(readBit(read_data, 3, 4) ? GLED_ON : GLED_OFF);

//    this->ui->M1AceptarProximaCaja->setStyleSheet(readBit(read_data, 4, 0) ? GLED_ON : GLED_OFF);
//    this->ui->M2AceptarProximaCaja->setStyleSheet(readBit(read_data, 4, 1) ? GLED_ON : GLED_OFF);
//    this->ui->M3AceptarProximaCaja->setStyleSheet(readBit(read_data, 4, 2) ? GLED_ON : GLED_OFF);
//    this->ui->DestinoCajaConocido->setStyleSheet(readBit(read_data, 4, 3) ? GLED_ON : GLED_OFF);
//    this->ui->M1Lleno->setStyleSheet(readBit(read_data, 4, 4) ? RLED_ON : RLED_OFF);
//    this->ui->M2Lleno->setStyleSheet(readBit(read_data, 4, 5) ? RLED_ON : RLED_OFF);
//    this->ui->M3Lleno->setStyleSheet(readBit(read_data, 4, 6) ? RLED_ON : RLED_OFF);
//    this->ui->MDLleno->setStyleSheet(readBit(read_data, 4, 7) ? RLED_ON : RLED_OFF);

//    this->ui->CajasMuelle1->setText(QString::number(readShort(read_data, 6)));
//    this->ui->CajasMuelle2->setText(QString::number(readShort(read_data, 8)));
//    this->ui->CajasMuelle3->setText(QString::number(readShort(read_data, 10)));
//    this->ui->CajasMuelleD->setText(QString::number(readShort(read_data, 12)));

    this->ui->S0->setStyleSheet(plcd->getBoolAt(0) ? GLED_ON : GLED_OFF);
    this->ui->S1cinta->setStyleSheet(plcd->getBoolAt(1) ? GLED_ON : GLED_OFF);
    this->ui->S2cinta->setStyleSheet(plcd->getBoolAt(2) ? GLED_ON : GLED_OFF);
    this->ui->S3cinta->setStyleSheet(plcd->getBoolAt(3) ? GLED_ON : GLED_OFF);
    this->ui->S1buffer->setStyleSheet(plcd->getBoolAt(4) ? GLED_ON : GLED_OFF);
    this->ui->S2buffer->setStyleSheet(plcd->getBoolAt(5) ? GLED_ON : GLED_OFF);
    this->ui->S3buffer->setStyleSheet(plcd->getBoolAt(6) ? GLED_ON : GLED_OFF);
    this->ui->SDbuffer->setStyleSheet(plcd->getBoolAt(7) ? GLED_ON : GLED_OFF);

    this->ui->C1e->setStyleSheet(plcd->getBoolAt(8) ? GLED_ON : GLED_OFF);
    this->ui->C2e->setStyleSheet(plcd->getBoolAt(9) ? GLED_ON : GLED_OFF);
    this->ui->C3e->setStyleSheet(plcd->getBoolAt(10) ? GLED_ON : GLED_OFF);
    this->ui->C1r->setStyleSheet(plcd->getBoolAt(11) ? GLED_ON : GLED_OFF);
    this->ui->C2r->setStyleSheet(plcd->getBoolAt(12) ? GLED_ON : GLED_OFF);
    this->ui->C3r->setStyleSheet(plcd->getBoolAt(13) ? GLED_ON : GLED_OFF);
    this->ui->C1f->setStyleSheet(plcd->getBoolAt(14) ? GLED_ON : GLED_OFF);
    this->ui->C2f->setStyleSheet(plcd->getBoolAt(15) ? GLED_ON : GLED_OFF);
    this->ui->C3f->setStyleSheet(plcd->getBoolAt(16) ? GLED_ON : GLED_OFF);
    this->ui->C1d->setStyleSheet(plcd->getBoolAt(17) ? GLED_ON : GLED_OFF);
    this->ui->C2d->setStyleSheet(plcd->getBoolAt(18) ? GLED_ON : GLED_OFF);
    this->ui->C3d->setStyleSheet(plcd->getBoolAt(19) ? GLED_ON : GLED_OFF);

    this->ui->M0->setStyleSheet(plcd->getBoolAt(20) ? GLED_ON : GLED_OFF);
    this->ui->M1->setStyleSheet(plcd->getBoolAt(21) ? GLED_ON : GLED_OFF);
    this->ui->M2->setStyleSheet(plcd->getBoolAt(22) ? GLED_ON : GLED_OFF);
    this->ui->M3->setStyleSheet(plcd->getBoolAt(23) ? GLED_ON : GLED_OFF);
    this->ui->M4->setStyleSheet(plcd->getBoolAt(24) ? GLED_ON : GLED_OFF);

    this->ui->M1AceptarProximaCaja->setStyleSheet(plcd->getBoolAt(25) ? GLED_ON : GLED_OFF);
    this->ui->M2AceptarProximaCaja->setStyleSheet(plcd->getBoolAt(26) ? GLED_ON : GLED_OFF);
    this->ui->M3AceptarProximaCaja->setStyleSheet(plcd->getBoolAt(27) ? GLED_ON : GLED_OFF);
    this->ui->DestinoCajaConocido->setStyleSheet(plcd->getBoolAt(28) ? GLED_ON : GLED_OFF);
    this->ui->M1Lleno->setStyleSheet(plcd->getBoolAt(29) ? RLED_ON : RLED_OFF);
    this->ui->M2Lleno->setStyleSheet(plcd->getBoolAt(30) ? RLED_ON : RLED_OFF);
    this->ui->M3Lleno->setStyleSheet(plcd->getBoolAt(31) ? RLED_ON : RLED_OFF);
    this->ui->MDLleno->setStyleSheet(plcd->getBoolAt(32) ? RLED_ON : RLED_OFF);

    this->ui->CajasMuelle1->setText(QString::number(plcd->getNumberAt(0)));
    this->ui->CajasMuelle2->setText(QString::number(plcd->getNumberAt(1)));
    this->ui->CajasMuelle3->setText(QString::number(plcd->getNumberAt(2)));
    this->ui->CajasMuelleD->setText(QString::number(plcd->getNumberAt(3)));
}