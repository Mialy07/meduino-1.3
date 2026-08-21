/********************************************************************************
** Form generated from reading UI file 'mainwindow2.0.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_0_H
#define UI_MAINWINDOW2_0_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *nom;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *accueil_btn;
    QPushButton *medoc_btn;
    QPushButton *Calendrier_btn;
    QPushButton *historique_btn;
    QStackedWidget *stackedWidget;
    QWidget *Accueil_page;
    QLabel *label;
    QLabel *temps_restant;
    QLabel *label_3;
    QWidget *info_medicament_page;
    QLabel *label_7;
    QTableWidget *tableau_medoc;
    QStackedWidget *stackedWidget_2;
    QWidget *ajout_page;
    QLabel *label_9;
    QFrame *frame_3;
    QFrame *frame_4;
    QLabel *label_10;
    QLineEdit *new_nom;
    QLabel *label_11;
    QComboBox *new_type;
    QLabel *label_12;
    QLabel *label_13;
    QSpinBox *new_stock;
    QSpinBox *new_dosage;
    QPushButton *new_confirm_btn;
    QPushButton *new_annuler_btn;
    QWidget *stock_page_2;
    QLabel *label_27;
    QSpinBox *modif_stock;
    QPushButton *restock_annuler_btn;
    QPushButton *restock_confirmer_btn;
    QLabel *restock_index;
    QWidget *options_page;
    QPushButton *ajout;
    QPushButton *modification;
    QPushButton *supression;
    QPushButton *restock_btn;
    QWidget *supression_page;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *modification_page;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *modif_nom;
    QLabel *label_25;
    QComboBox *modif_type;
    QLabel *label_26;
    QSpinBox *modif_dosage;
    QLabel *label_28;
    QSpinBox *modif_seuil;
    QLabel *label_29;
    QSpinBox *modif_boite;
    QPushButton *modif_confirm_btn;
    QPushButton *modif_annuler_btn;
    QLabel *modif_index;
    QWidget *calendrier_page;
    QLabel *label_5;
    QTableWidget *tableau_calendrier;
    QStackedWidget *calendrier_modification_page;
    QWidget *page;
    QPushButton *calendrier_modif_btn;
    QPushButton *calendrier_temps_btn;
    QWidget *page_2;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QSpinBox *spinMatin;
    QSpinBox *spinMidi;
    QSpinBox *spinSoir;
    QPushButton *calendrier_annuler_btn;
    QPushButton *calendrier_confirmer_btn;
    QLabel *calendrier_modif_index;
    QWidget *page_temps;
    QLabel *label_17;
    QTimeEdit *priseSoir;
    QTimeEdit *priseMidi;
    QLabel *label_19;
    QLabel *label_18;
    QTimeEdit *priseMatin;
    QPushButton *temps_annuler_btn;
    QPushButton *temps_confirmer_btn;
    QWidget *historique_page;
    QLabel *label_6;
    QCalendarWidget *historique_calendarWidget;
    QTableWidget *Historique_tableau;
    QWidget *stock_page;
    QWidget *boite_page;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1315, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 301, 551));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        nom = new QLabel(frame);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(130, 20, 101, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Serif CJK JP"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setStrikeOut(false);
        font.setKerning(true);
        nom->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 20, 61, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 100, 301, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        accueil_btn = new QPushButton(verticalLayoutWidget);
        accueil_btn->setObjectName(QString::fromUtf8("accueil_btn"));
        accueil_btn->setIconSize(QSize(30, 30));
        accueil_btn->setAutoDefault(false);

        verticalLayout->addWidget(accueil_btn);

        medoc_btn = new QPushButton(verticalLayoutWidget);
        medoc_btn->setObjectName(QString::fromUtf8("medoc_btn"));

        verticalLayout->addWidget(medoc_btn);

        Calendrier_btn = new QPushButton(verticalLayoutWidget);
        Calendrier_btn->setObjectName(QString::fromUtf8("Calendrier_btn"));

        verticalLayout->addWidget(Calendrier_btn);

        historique_btn = new QPushButton(verticalLayoutWidget);
        historique_btn->setObjectName(QString::fromUtf8("historique_btn"));

        verticalLayout->addWidget(historique_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(310, 10, 1001, 541));
        QFont font2;
        font2.setPointSize(13);
        stackedWidget->setFont(font2);
        Accueil_page = new QWidget();
        Accueil_page->setObjectName(QString::fromUtf8("Accueil_page"));
        label = new QLabel(Accueil_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 30, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("URW Bookman"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        label->setFont(font3);
        label->setAutoFillBackground(false);
        temps_restant = new QLabel(Accueil_page);
        temps_restant->setObjectName(QString::fromUtf8("temps_restant"));
        temps_restant->setGeometry(QRect(30, 160, 871, 211));
        temps_restant->setScaledContents(false);
        temps_restant->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Accueil_page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 120, 301, 20));
        stackedWidget->addWidget(Accueil_page);
        info_medicament_page = new QWidget();
        info_medicament_page->setObjectName(QString::fromUtf8("info_medicament_page"));
        label_7 = new QLabel(info_medicament_page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 20, 401, 31));
        label_7->setFont(font3);
        label_7->setAutoFillBackground(false);
        tableau_medoc = new QTableWidget(info_medicament_page);
        tableau_medoc->setObjectName(QString::fromUtf8("tableau_medoc"));
        tableau_medoc->setGeometry(QRect(10, 90, 741, 371));
        tableau_medoc->setGridStyle(Qt::DotLine);
        tableau_medoc->horizontalHeader()->setVisible(true);
        tableau_medoc->horizontalHeader()->setMinimumSectionSize(50);
        tableau_medoc->horizontalHeader()->setDefaultSectionSize(120);
        stackedWidget_2 = new QStackedWidget(info_medicament_page);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(770, 20, 211, 451));
        ajout_page = new QWidget();
        ajout_page->setObjectName(QString::fromUtf8("ajout_page"));
        label_9 = new QLabel(ajout_page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 20, 161, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setItalic(true);
        label_9->setFont(font4);
        frame_3 = new QFrame(ajout_page);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 211, 441));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 211, 71));
        frame_4->setAutoFillBackground(false);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 80, 66, 18));
        new_nom = new QLineEdit(frame_3);
        new_nom->setObjectName(QString::fromUtf8("new_nom"));
        new_nom->setGeometry(QRect(20, 100, 181, 26));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 140, 66, 18));
        new_type = new QComboBox(frame_3);
        new_type->addItem(QString());
        new_type->addItem(QString());
        new_type->addItem(QString());
        new_type->setObjectName(QString::fromUtf8("new_type"));
        new_type->setGeometry(QRect(20, 160, 181, 26));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 200, 66, 18));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 260, 66, 18));
        new_stock = new QSpinBox(frame_3);
        new_stock->setObjectName(QString::fromUtf8("new_stock"));
        new_stock->setGeometry(QRect(20, 280, 181, 27));
        new_stock->setMaximum(9999);
        new_dosage = new QSpinBox(frame_3);
        new_dosage->setObjectName(QString::fromUtf8("new_dosage"));
        new_dosage->setGeometry(QRect(20, 220, 181, 27));
        new_dosage->setMaximum(9999);
        new_confirm_btn = new QPushButton(frame_3);
        new_confirm_btn->setObjectName(QString::fromUtf8("new_confirm_btn"));
        new_confirm_btn->setGeometry(QRect(110, 380, 88, 26));
        new_annuler_btn = new QPushButton(frame_3);
        new_annuler_btn->setObjectName(QString::fromUtf8("new_annuler_btn"));
        new_annuler_btn->setGeometry(QRect(20, 380, 88, 26));
        stackedWidget_2->addWidget(ajout_page);
        stock_page_2 = new QWidget();
        stock_page_2->setObjectName(QString::fromUtf8("stock_page_2"));
        label_27 = new QLabel(stock_page_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 210, 66, 18));
        modif_stock = new QSpinBox(stock_page_2);
        modif_stock->setObjectName(QString::fromUtf8("modif_stock"));
        modif_stock->setGeometry(QRect(20, 240, 181, 27));
        modif_stock->setMaximum(9999);
        restock_annuler_btn = new QPushButton(stock_page_2);
        restock_annuler_btn->setObjectName(QString::fromUtf8("restock_annuler_btn"));
        restock_annuler_btn->setGeometry(QRect(20, 320, 80, 26));
        restock_confirmer_btn = new QPushButton(stock_page_2);
        restock_confirmer_btn->setObjectName(QString::fromUtf8("restock_confirmer_btn"));
        restock_confirmer_btn->setGeometry(QRect(110, 320, 80, 26));
        restock_index = new QLabel(stock_page_2);
        restock_index->setObjectName(QString::fromUtf8("restock_index"));
        restock_index->setGeometry(QRect(70, 360, 0, 0));
        stackedWidget_2->addWidget(stock_page_2);
        options_page = new QWidget();
        options_page->setObjectName(QString::fromUtf8("options_page"));
        ajout = new QPushButton(options_page);
        ajout->setObjectName(QString::fromUtf8("ajout"));
        ajout->setGeometry(QRect(0, 120, 211, 51));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(210, 255, 253, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(232, 255, 254, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(105, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(140, 170, 169, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush8(QColor(239, 239, 239, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        QBrush brush9(QColor(202, 202, 202, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        QBrush brush10(QColor(159, 159, 159, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        QBrush brush11(QColor(184, 184, 184, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush12(QColor(118, 118, 118, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush12);
        QBrush brush13(QColor(247, 247, 247, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush14(QColor(0, 0, 0, 128));
        brush14.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush15(QColor(177, 177, 177, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        ajout->setPalette(palette);
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(true);
        font5.setUnderline(false);
        font5.setStrikeOut(false);
        ajout->setFont(font5);
        modification = new QPushButton(options_page);
        modification->setObjectName(QString::fromUtf8("modification"));
        modification->setGeometry(QRect(0, 280, 211, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush16(QColor(0, 207, 186, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush16);
        QBrush brush17(QColor(56, 255, 235, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush17);
        QBrush brush18(QColor(28, 231, 210, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        QBrush brush19(QColor(0, 104, 93, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush19);
        QBrush brush20(QColor(0, 138, 124, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush21(QColor(127, 231, 220, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush21);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush17);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        modification->setPalette(palette1);
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setItalic(true);
        modification->setFont(font6);
        supression = new QPushButton(options_page);
        supression->setObjectName(QString::fromUtf8("supression"));
        supression->setGeometry(QRect(0, 200, 211, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush22(QColor(97, 255, 242, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush22);
        QBrush brush23(QColor(224, 255, 253, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush23);
        QBrush brush24(QColor(160, 255, 247, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush24);
        QBrush brush25(QColor(48, 127, 121, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush25);
        QBrush brush26(QColor(65, 170, 161, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush26);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush22);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush27(QColor(176, 255, 248, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush27);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush25);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush23);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush24);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush25);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush26);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush25);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush25);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        supression->setPalette(palette2);
        supression->setFont(font6);
        restock_btn = new QPushButton(options_page);
        restock_btn->setObjectName(QString::fromUtf8("restock_btn"));
        restock_btn->setGeometry(QRect(0, 360, 211, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush19);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush21);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        restock_btn->setPalette(palette3);
        restock_btn->setFont(font6);
        stackedWidget_2->addWidget(options_page);
        supression_page = new QWidget();
        supression_page->setObjectName(QString::fromUtf8("supression_page"));
        label_21 = new QLabel(supression_page);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 20, 161, 31));
        label_21->setFont(font4);
        label_22 = new QLabel(supression_page);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 80, 181, 41));
        QFont font7;
        font7.setPointSize(10);
        label_22->setFont(font7);
        label_22->setWordWrap(true);
        stackedWidget_2->addWidget(supression_page);
        modification_page = new QWidget();
        modification_page->setObjectName(QString::fromUtf8("modification_page"));
        label_23 = new QLabel(modification_page);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 20, 161, 31));
        label_23->setFont(font4);
        label_24 = new QLabel(modification_page);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 80, 66, 18));
        modif_nom = new QLineEdit(modification_page);
        modif_nom->setObjectName(QString::fromUtf8("modif_nom"));
        modif_nom->setGeometry(QRect(20, 100, 181, 26));
        label_25 = new QLabel(modification_page);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 140, 66, 18));
        modif_type = new QComboBox(modification_page);
        modif_type->addItem(QString());
        modif_type->addItem(QString());
        modif_type->addItem(QString());
        modif_type->setObjectName(QString::fromUtf8("modif_type"));
        modif_type->setGeometry(QRect(20, 160, 181, 26));
        label_26 = new QLabel(modification_page);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 200, 66, 18));
        modif_dosage = new QSpinBox(modification_page);
        modif_dosage->setObjectName(QString::fromUtf8("modif_dosage"));
        modif_dosage->setGeometry(QRect(20, 220, 181, 27));
        modif_dosage->setMaximum(9999);
        label_28 = new QLabel(modification_page);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 270, 66, 18));
        modif_seuil = new QSpinBox(modification_page);
        modif_seuil->setObjectName(QString::fromUtf8("modif_seuil"));
        modif_seuil->setGeometry(QRect(20, 290, 181, 27));
        modif_seuil->setMaximum(9999);
        label_29 = new QLabel(modification_page);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(20, 320, 66, 18));
        modif_boite = new QSpinBox(modification_page);
        modif_boite->setObjectName(QString::fromUtf8("modif_boite"));
        modif_boite->setGeometry(QRect(20, 340, 181, 27));
        modif_boite->setMaximum(9999);
        modif_confirm_btn = new QPushButton(modification_page);
        modif_confirm_btn->setObjectName(QString::fromUtf8("modif_confirm_btn"));
        modif_confirm_btn->setGeometry(QRect(110, 390, 88, 26));
        modif_annuler_btn = new QPushButton(modification_page);
        modif_annuler_btn->setObjectName(QString::fromUtf8("modif_annuler_btn"));
        modif_annuler_btn->setGeometry(QRect(20, 390, 88, 26));
        modif_index = new QLabel(modification_page);
        modif_index->setObjectName(QString::fromUtf8("modif_index"));
        modif_index->setGeometry(QRect(20, 430, 0, 0));
        stackedWidget_2->addWidget(modification_page);
        stackedWidget->addWidget(info_medicament_page);
        calendrier_page = new QWidget();
        calendrier_page->setObjectName(QString::fromUtf8("calendrier_page"));
        label_5 = new QLabel(calendrier_page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(420, 20, 161, 31));
        label_5->setFont(font3);
        label_5->setAutoFillBackground(false);
        tableau_calendrier = new QTableWidget(calendrier_page);
        tableau_calendrier->setObjectName(QString::fromUtf8("tableau_calendrier"));
        tableau_calendrier->setGeometry(QRect(10, 100, 741, 361));
        calendrier_modification_page = new QStackedWidget(calendrier_page);
        calendrier_modification_page->setObjectName(QString::fromUtf8("calendrier_modification_page"));
        calendrier_modification_page->setGeometry(QRect(770, 100, 201, 361));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        calendrier_modif_btn = new QPushButton(page);
        calendrier_modif_btn->setObjectName(QString::fromUtf8("calendrier_modif_btn"));
        calendrier_modif_btn->setGeometry(QRect(20, 190, 171, 41));
        calendrier_temps_btn = new QPushButton(page);
        calendrier_temps_btn->setObjectName(QString::fromUtf8("calendrier_temps_btn"));
        calendrier_temps_btn->setGeometry(QRect(20, 140, 171, 41));
        calendrier_modification_page->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 61, 21));
        label_14->setFont(font2);
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 140, 51, 21));
        label_16 = new QLabel(page_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 240, 51, 21));
        spinMatin = new QSpinBox(page_2);
        spinMatin->setObjectName(QString::fromUtf8("spinMatin"));
        spinMatin->setGeometry(QRect(10, 50, 181, 31));
        spinMidi = new QSpinBox(page_2);
        spinMidi->setObjectName(QString::fromUtf8("spinMidi"));
        spinMidi->setGeometry(QRect(10, 160, 181, 31));
        spinSoir = new QSpinBox(page_2);
        spinSoir->setObjectName(QString::fromUtf8("spinSoir"));
        spinSoir->setGeometry(QRect(10, 260, 181, 31));
        calendrier_annuler_btn = new QPushButton(page_2);
        calendrier_annuler_btn->setObjectName(QString::fromUtf8("calendrier_annuler_btn"));
        calendrier_annuler_btn->setGeometry(QRect(10, 320, 91, 26));
        calendrier_confirmer_btn = new QPushButton(page_2);
        calendrier_confirmer_btn->setObjectName(QString::fromUtf8("calendrier_confirmer_btn"));
        calendrier_confirmer_btn->setGeometry(QRect(110, 320, 91, 26));
        calendrier_modif_index = new QLabel(page_2);
        calendrier_modif_index->setObjectName(QString::fromUtf8("calendrier_modif_index"));
        calendrier_modif_index->setGeometry(QRect(120, 240, 0, 0));
        calendrier_modification_page->addWidget(page_2);
        page_temps = new QWidget();
        page_temps->setObjectName(QString::fromUtf8("page_temps"));
        label_17 = new QLabel(page_temps);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 58, 18));
        priseSoir = new QTimeEdit(page_temps);
        priseSoir->setObjectName(QString::fromUtf8("priseSoir"));
        priseSoir->setGeometry(QRect(30, 180, 118, 27));
        priseMidi = new QTimeEdit(page_temps);
        priseMidi->setObjectName(QString::fromUtf8("priseMidi"));
        priseMidi->setGeometry(QRect(30, 110, 118, 27));
        label_19 = new QLabel(page_temps);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 150, 58, 18));
        label_18 = new QLabel(page_temps);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 90, 58, 18));
        priseMatin = new QTimeEdit(page_temps);
        priseMatin->setObjectName(QString::fromUtf8("priseMatin"));
        priseMatin->setGeometry(QRect(30, 40, 118, 27));
        temps_annuler_btn = new QPushButton(page_temps);
        temps_annuler_btn->setObjectName(QString::fromUtf8("temps_annuler_btn"));
        temps_annuler_btn->setGeometry(QRect(0, 320, 91, 26));
        temps_confirmer_btn = new QPushButton(page_temps);
        temps_confirmer_btn->setObjectName(QString::fromUtf8("temps_confirmer_btn"));
        temps_confirmer_btn->setGeometry(QRect(100, 320, 91, 26));
        calendrier_modification_page->addWidget(page_temps);
        stackedWidget->addWidget(calendrier_page);
        historique_page = new QWidget();
        historique_page->setObjectName(QString::fromUtf8("historique_page"));
        label_6 = new QLabel(historique_page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 30, 161, 31));
        label_6->setFont(font3);
        label_6->setAutoFillBackground(false);
        historique_calendarWidget = new QCalendarWidget(historique_page);
        historique_calendarWidget->setObjectName(QString::fromUtf8("historique_calendarWidget"));
        historique_calendarWidget->setGeometry(QRect(20, 90, 271, 371));
        Historique_tableau = new QTableWidget(historique_page);
        Historique_tableau->setObjectName(QString::fromUtf8("Historique_tableau"));
        Historique_tableau->setGeometry(QRect(310, 90, 661, 371));
        stackedWidget->addWidget(historique_page);
        stock_page = new QWidget();
        stock_page->setObjectName(QString::fromUtf8("stock_page"));
        stackedWidget->addWidget(stock_page);
        boite_page = new QWidget();
        boite_page->setObjectName(QString::fromUtf8("boite_page"));
        stackedWidget->addWidget(boite_page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1315, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        accueil_btn->setDefault(false);
        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(3);
        calendrier_modification_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Bonjour", nullptr));
        accueil_btn->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        medoc_btn->setText(QCoreApplication::translate("MainWindow", "Info Medicament", nullptr));
        Calendrier_btn->setText(QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        historique_btn->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        temps_restant->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Temps restant avant procahine prise:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Informations medicaments", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ajout medicament", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        new_type->setItemText(0, QCoreApplication::translate("MainWindow", "Pillule", nullptr));
        new_type->setItemText(1, QCoreApplication::translate("MainWindow", "Gellule", nullptr));
        new_type->setItemText(2, QCoreApplication::translate("MainWindow", "Sirop", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Dosage :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Stock :", nullptr));
        new_confirm_btn->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        new_annuler_btn->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Stock :", nullptr));
        restock_annuler_btn->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        restock_confirmer_btn->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        restock_index->setText(QString());
        ajout->setText(QCoreApplication::translate("MainWindow", "Ajouter un medicament", nullptr));
        modification->setText(QCoreApplication::translate("MainWindow", "Modifier un medicament", nullptr));
        supression->setText(QCoreApplication::translate("MainWindow", "Supprimer un medicament", nullptr));
        restock_btn->setText(QCoreApplication::translate("MainWindow", "Restock", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Suppression m\303\251dicament", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Veuillez s\303\251lectionner un m\303\251dicament dans le tableau et cliquer sur Supprimer", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Modification m\303\251dicament", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        modif_type->setItemText(0, QCoreApplication::translate("MainWindow", "Pillule", nullptr));
        modif_type->setItemText(1, QCoreApplication::translate("MainWindow", "Gellule", nullptr));
        modif_type->setItemText(2, QCoreApplication::translate("MainWindow", "Sirop", nullptr));

        label_26->setText(QCoreApplication::translate("MainWindow", "Dosage :", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Seuil :", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Bo\303\256te :", nullptr));
        modif_confirm_btn->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        modif_annuler_btn->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        modif_index->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        calendrier_modif_btn->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        calendrier_temps_btn->setText(QCoreApplication::translate("MainWindow", "Temps", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Matin:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Midi:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Soir:", nullptr));
        calendrier_annuler_btn->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        calendrier_confirmer_btn->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        calendrier_modif_index->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Matin:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Soir:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Midi:", nullptr));
        temps_annuler_btn->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        temps_confirmer_btn->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_0_H
