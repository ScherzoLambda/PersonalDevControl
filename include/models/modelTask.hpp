#ifndef MODELTASK_H
#define MODELTASK_H

#include <string>
#include <QString>
using namespace std;
// TODO: usar  nlohmann/json 
class ModelTask {
public:
    static string document_task(const string& id, const string& tipo, const string& descricao, const string& total, const string& inicio, const string& fim);
    
};
#endif // MODELTASK_H