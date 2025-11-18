#include <models/modelTask.hpp>
#include <QString>
#include <QCryptographicHash>

using namespace std;


string ModelTask::document_task(const string& id, const string& tipo, const string& descricao, const string& total, const string& inicio, const string& fim)
{   
    string documento = ",\"document\":{\"id_usuario\": \"" + id + "\", \"tipo_task\": \"" + tipo + "\",\"desc_task\": \"" + descricao + 
        "\",\"horas_gastas\": \"" + total + "\", \"hora_inicio\": \""+ inicio + ",\"hora_fim\": \"" + fim + "\" }";
    return documento;
}

