#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    loadSettings();
    connect(ui->ok_cancel, SIGNAL(accepted()), this, SLOT(saveSettings()));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::saveSettings()
{
    QSettings settings(QString("config.ini"), QSettings::IniFormat); /* load settings */
    settings.setValue(tr("Compiler/build_command"), ui->buildCommand->text());
    settings.setValue(tr("Compiler/compile_command"), ui->compileCommand->text());

    settings.setValue(tr("Editor/font_size"), ui->fontSizeSwitcher->value());
    settings.setValue(tr("Editor/font_type"), ui->fontSwitcher->currentText());
}

void SettingsDialog::loadSettings()
{
    QSettings settings(QString("config.ini"), QSettings::IniFormat); /* load settings */
    ui->buildCommand->setText(settings.value("Compiler/build_command").toString());
    ui->compileCommand->setText(settings.value("Compiler/compile_command").toString());

    ui->fontSizeSwitcher->setValue(settings.value("Editor/font_size").toInt());
    ui->fontSwitcher->setCurrentText(settings.value("Editor/font_type").toString());
}
