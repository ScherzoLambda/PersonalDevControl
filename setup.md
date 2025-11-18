# PersonalDevControl - Setup Guide

Este guia fornece instruções detalhadas para baixar e configurar o PersonalDevControl para seu uso.


## Escolha sua plataforma

**linux**: link para baixar versão para linux

**macos**: link para baixar versão para macos

**win10/11**: link para baixar versão para windows

- Siga as instruções de instalação especifica para sua plataforma paraa instalação correta.

## Configuração

- Execute o programa e por ser o primeiro acesso sera iniciado o processo de de configuração do banco de dados que sera utilizado pela aplicação.

- Basta entrar com os dados da sua instancia do mongodb, é gratuito.
- - Procure pela path string de acesso a instancia, no site do mongo. A string em questão se parece com o exemplo a seguir:

```
mongodb+srv://<db_username>:<db_password>@<cluster-name>.oiglee6.mongodb.net/?appName=<cluster-name>
```

Por padrão ao definir o banco, é executado uma seed de teste para criação de um usuário demo.
Nesta seed definimos dados de 2 meses de traking de tarefas, com todos os dias com horas mapeadas e com tasks variadas. Você pode conferir estes dados com vizualização em um dashboard descritivos das tarefas realizadas, média de horas e entre outras métricas.
**Voce pode deletar
Usuário demo:
```
   email: demo@email.com
   senha: demo12345
```

Crie uma conta e acesse o aplicativo.
Pronto, projeto configurado e pronto para uso.

