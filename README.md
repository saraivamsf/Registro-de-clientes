# Registro-de-clientes

Este é um projeto simples em linguagem C para cadastro e consulta de clientes utilizando arquivos de texto.

---

## 🚀 Funcionalidades

- Registrar novo cliente
- Gerar ID automático incremental
- Armazenar dados em arquivo `.txt`
- Buscar cliente por ID (em desenvolvimento)
- Listar clientes (em desenvolvimento)

---

## 📁 Estrutura do cliente

Cada cliente possui:

- ID (gerado automaticamente)
- Nome
- Idade
- Telefone
- Email

---

## 💾 Armazenamento

Os dados são salvos em um arquivo texto chamado `registro.txt`.

Cada linha segue o formato:
id;nome;idade;telefone;email

Exemplo de conteúdo:
1;João;20;31999999999;joao@email.com
2;Maria;18;31988888888;maria@email.com

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Estruturas (`struct`)
- Manipulação de arquivos (`fopen`, `fprintf`, `fscanf`)
- Controle de fluxo

---

## 📌 Objetivo do projeto

Este projeto foi desenvolvido com o objetivo de praticar:

- Estruturas em C
- Manipulação de arquivos em texto
- Organização de sistemas simples
- Lógica de programação