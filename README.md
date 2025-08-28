# PersonalDevControl

![Build Status](https://github.com/ScherzoLambda/PersonalDevControl/workflows/Build%20Qt%20C++%20App/badge.svg)

PersonalDevControl é uma aplicação de controle pessoal de desenvolvimento construída em C++ usando Qt6 e CMake. A aplicação permite gerenciar tarefas de desenvolvimento pessoal com integração à API do MongoDB.

## 🚀 Funcionalidades

- **Sistema de Login**: Autenticação de usuários via MongoDB
- **Controle de Tempo**: Timer para acompanhar tempo gasto em tarefas
- **Interface Qt6**: Interface moderna e responsiva
- **API MongoDB**: Integração com banco de dados MongoDB via cURL
- **Multiplataforma**: Suporte para Linux, Windows e macOS

## 🛠️ Tecnologias

- **C++17**: Linguagem principal
- **Qt6**: Framework de interface gráfica
- **CMake**: Sistema de build
- **libcurl**: Cliente HTTP para API MongoDB
- **MongoDB**: Banco de dados

## 📁 Estrutura do Projeto

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

## ⚡ Quick Start

### Pré-requisitos

- Qt6 (6.5.0 ou superior)
- CMake 3.16+
- libcurl
- Compilador C++17 (GCC, Clang ou MSVC)

### Instalação

1. **Clone o repositório:**
```bash
git clone https://github.com/ScherzoLambda/PersonalDevControl.git
cd PersonalDevControl
```

2. **Configure e compile:**
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

3. **Execute:**
```bash
./PersonalDevControl
```

## 🔧 Desenvolvimento

### CLion Setup

Para configurar o projeto no CLion, consulte o [setup.md](setup.md) que contém instruções detalhadas.

### Build Manual

```bash
# Debug build
mkdir build-debug
cd build-debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# Release build
mkdir build-release
cd build-release
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## 🏗️ CI/CD

O projeto usa GitHub Actions para integração contínua. A cada push ou pull request, o código é automaticamente compilado e testado em ambiente Ubuntu.

## 📖 Documentação

- [Setup Guide](setup.md) - Configuração detalhada do ambiente de desenvolvimento
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

## 👥 Autores

- **ScherzoLambda** - *Trabalho inicial* - [ScherzoLambda](https://github.com/ScherzoLambda)

## 🙏 Agradecimentos

- Qt Framework pela excelente biblioteca de interface gráfica
- MongoDB pela API robusta de banco de dados
- Comunidade open source pelas ferramentas e bibliotecas utilizadas

---

⭐ **Se este projeto foi útil para você, considere dar uma estrela!**