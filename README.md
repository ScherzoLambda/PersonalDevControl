# PersonalDevControl [Work in Progress]

![Build Status](https://github.com/ScherzoLambda/PersonalDevControl/workflows/Build%20Qt%20C++%20App/badge.svg)

PersonalDevControl é uma aplicação de controle pessoal de desenvolvimento construída em C++ usando Qt6 e CMake. A aplicação permite gerenciar tarefas de desenvolvimento pessoal com integração à API do MongoDB.


## 🚀 Funcionalidades

- **Sistema de Login**: Autenticação de usuários via MongoDB
- **Controle de Tempo**: Timer para acompanhar tempo gasto em tarefas
- **API MongoDB**: Integração com banco de dados MongoDB definido pelo usuário.
- **Multiplataforma**: Suporte para Linux, Windows e macOS

## 🛠️ Tecnologias

- **C++17**: Linguagem principal
- **Qt6**: Framework de interface gráfica
- **CMake**: Sistema de build
- **mongocxx**: Driver oficial MongoDB C++ para acesso ao banco de dados

## 📁 Estrutura do Projeto
- - Sera alterado na proxima atualização

```
PersonalDevControl/
├── docs/                 # Documentação
├── src/                  # Código-fonte principal
│   ├── core/             # Lógica central e API
│   ├── ui/               # Interface do usuário
│   ├── models/           # Modelos de dados
│   ├── controllers/      # Controladores (futuro)
│   ├── utils/            # Utilitários (futuro)
│   └── main.cpp          # Ponto de entrada
├── resources/            # Recursos da aplicação
│   ├── icons/            # Ícones
│   ├── images/           # Imagens
│   └── translations/     # Traduções
├── tests/                # Testes unitários
├── .github/workflows/    # CI/CD GitHub Actions
├── CMakeLists.txt        # Configuração CMake
└── setup.md              # Guia de configuração
```


## 📖 Documentação

- [Setup Guide](setup.md) - Instruções para instalação e configuração inicial obrigatória para uso.
- [API Documentation](docs/) - Documentação da API (em desenvolvimento)

## 🤝 Contribuição

Contribuições são bem-vindas! Por favor:

1. Fork o projeto
2. Crie uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

## 📝 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.


## 🙏 Agradecimentos

- Qt Framework pela excelente biblioteca de interface gráfica
- MongoDB pelo driver oficial mongocxx e banco de dados robusto
- Comunidade open source pelas ferramentas e bibliotecas utilizadas

---
