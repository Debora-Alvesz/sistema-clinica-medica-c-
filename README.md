# 🏥 Sistema de Gerenciamento de Clínica Médica

## 📝 Sobre o Projeto
Este é um projeto acadêmico desenvolvido para a disciplina de **Estrutura de Dados**. Trata-se de uma simulação de um sistema para clínicas médicas, totalmente desenvolvido em **C**. O objetivo principal foi aplicar conceitos de modularização de código, manipulação de arquivos e estruturas de dados dinâmicas (como listas).

Todas as informações de pacientes e consultas são salvas e lidas diretamente em arquivos de texto/binários, garantindo a persistência dos dados entre as execuções.

## ⚙️ Funcionalidades

O sistema possui um menu interativo no console com as seguintes opções:

**👥 Gerenciamento de Pacientes:**
* Cadastrar novo paciente (inserção no início da lista)
* Listar todos os pacientes cadastrados
* Buscar paciente específico pelo CPF
* Alterar dados cadastrais do paciente
* Excluir paciente do sistema

**🩺 Gerenciamento de Consultas:**
* Agendar nova consulta
* Listar todas as consultas
* Buscar consulta pelo CPF do paciente
* Alterar dados de uma consulta existente
* Excluir consulta

**📊 Relatórios:**
* Listar consultas filtradas por especialidade médica
* Listar consultas filtradas por data
* Listar apenas os pacientes que possuem consultas agendadas ativas

## 🛠️ Tecnologias e Conceitos Utilizados
* **Linguagem:** C
* **Estrutura de Dados:** Listas Encadeadas (Manipulação de ponteiros)
* **Arquitetura:** Modularização (separação em arquivos `.c` e `.h`)
* **Persistência:** Manipulação de Arquivos (File I/O)
* **IDE:** Code::Blocks
