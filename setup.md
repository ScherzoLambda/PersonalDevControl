# PersonalDevControl - Setup Guide

Este guia fornece instruções detalhadas para configurar, abrir e buildar o projeto PersonalDevControl no CLion usando Qt6 e CMake.

## Pré-requisitos

### 1. Instalação do Qt6

#### Linux (Ubuntu/Debian)
```bash
# Instalar Qt6 via repositório oficial
sudo apt update
sudo apt install qt6-base-dev qt6-tools-dev cmake build-essential

# Ou baixar do site oficial Qt
# https://www.qt.io/download-qt-installer
```

#### Windows
1. Baixar Qt6 do site oficial: https://www.qt.io/download-qt-installer
2. Executar o instalador e selecionar:
   - Qt 6.5.0 ou superior
   - MSVC 2019/2022 64-bit (recomendado)
   - Qt Creator (opcional)
   - CMake

#### macOS
```bash
# Via Homebrew
brew install qt@6 cmake

# Ou baixar do site oficial Qt
```

### 2. Dependências Externas

#### libcurl (para API MongoDB)
```bash
# Linux
sudo apt install libcurl4-openssl-dev pkg-config

# Windows (usando vcpkg)
vcpkg install curl

# macOS
brew install curl
```

## Configuração no CLion

### 1. Abrir o Projeto

1. **Abrir CLion**
2. **File → Open** ou **Open Project**
3. Navegar para a pasta do projeto `PersonalDevControl`
4. Selecionar o arquivo `CMakeLists.txt` e abrir

### 2. Configurar Toolchains

1. **File → Settings** (ou **CLion → Preferences** no macOS)
2. **Build, Execution, Deployment → Toolchains**
3. Verificar se há uma toolchain configurada:
   - **Linux**: GCC ou Clang
   - **Windows**: MSVC ou MinGW
   - **macOS**: Clang

### 3. Configurar CMake

1. **File → Settings → Build, Execution, Deployment → CMake**
2. Configurar perfis de build:

#### Debug Profile
- **Name**: Debug
- **Build type**: Debug
- **CMake options**: `-DCMAKE_BUILD_TYPE=Debug`
- **Build directory**: `cmake-build-debug`

#### Release Profile
- **Name**: Release
- **Build type**: Release
- **CMake options**: `-DCMAKE_BUILD_TYPE=Release`
- **Build directory**: `cmake-build-release`

### 4. Configurar Qt6 (se necessário)

Se o CMake não encontrar automaticamente o Qt6:

1. Adicionar nas **CMake options**:
```
-DCMAKE_PREFIX_PATH=/path/to/Qt/6.5.0/gcc_64
```

#### Caminhos típicos do Qt6:

- **Linux**: `/usr/lib/x86_64-linux-gnu/cmake/Qt6` ou `/opt/Qt/6.5.0/gcc_64`
- **Windows**: `C:\Qt\6.5.0\msvc2019_64`
- **macOS**: `/usr/local/opt/qt@6` ou `/opt/homebrew/opt/qt@6`

## Build e Execução

### 1. Build do Projeto

1. **Build → Build Project** (Ctrl+F9)
2. Ou clicar no ícone de build na toolbar
3. Aguardar a compilação completar

### 2. Configurar Run Configuration

1. **Run → Edit Configurations...**
2. Selecionar o target `PersonalDevControl`
3. Verificar se o **Executable** está correto
4. **Working directory**: definir como diretório raiz do projeto

### 3. Executar

1. **Run → Run 'PersonalDevControl'** (Shift+F10)
2. Ou clicar no ícone de play verde

## Estrutura do Projeto

```
PersonalDevControl/
├── docs/                 # Documentação
├── src/                  # Código-fonte
│   ├── core/             # API MongoDB e lógica central
│   ├── ui/               # Interface do usuário
│   ├── models/           # Modelos de dados
│   ├── controllers/      # Controladores (futuro)
│   ├── utils/            # Utilitários (futuro)
│   └── main.cpp          # Ponto de entrada
├── resources/            # Recursos Qt (imagens, ícones, etc.)
├── tests/                # Testes (futuro)
├── build/                # Arquivos de build (ignorado pelo git)
├── .github/workflows/    # CI/CD GitHub Actions
├── CMakeLists.txt        # Configuração CMake
├── .gitignore            # Arquivos ignorados pelo Git
├── README.md             # Documentação principal
└── setup.md              # Este arquivo
```

## Debugging

### 1. Configurar Debugger

1. **Run → Edit Configurations...**
2. Criar nova configuração **CMake Application**
3. Definir **Target**: PersonalDevControl
4. **Build type**: Debug

### 2. Breakpoints

1. Clicar na margem esquerda do editor para adicionar breakpoints
2. **Run → Debug 'PersonalDevControl'** (Shift+F9)

## Integração de Testes (Futuro)

Para adicionar testes unitários:

1. Adicionar find_package(Qt6Test REQUIRED) no CMakeLists.txt
2. Criar arquivos de teste na pasta `tests/`
3. Configurar CTest para execução automática

## Solução de Problemas

### Qt6 não encontrado
```cmake
# Adicionar ao CMakeLists.txt se necessário
set(CMAKE_PREFIX_PATH "/path/to/Qt/6.5.0/gcc_64")
```

### libcurl não encontrado
```bash
# Linux - instalar dev package
sudo apt install libcurl4-openssl-dev pkg-config

# Windows - verificar vcpkg
vcpkg list curl
```

### Erro de compilação com MOC
1. Verificar se os arquivos .h com Q_OBJECT estão listados em qt6_add_executable
2. Executar **Build → Clean** e rebuild

### Problemas de encoding
1. Verificar se os arquivos estão salvos em UTF-8
2. Configurar CLion: **File → Settings → Editor → File Encodings**

## Recursos Úteis

- [Documentação Qt6](https://doc.qt.io/qt-6/)
- [CMake Documentation](https://cmake.org/documentation/)
- [CLion Help](https://www.jetbrains.com/help/clion/)
- [Qt CMake Manual](https://doc.qt.io/qt-6/cmake-manual.html)

## Contribuição

Para contribuir com o projeto:

1. Fork o repositório
2. Criar branch feature: `git checkout -b feature/nova-funcionalidade`
3. Commit mudanças: `git commit -am 'Adiciona nova funcionalidade'`
4. Push para branch: `git push origin feature/nova-funcionalidade`
5. Abrir Pull Request