# Get Next Line (GNL)

El proyecto **Get Next Line (GNL)** es parte del currículo de 42 y tiene como objetivo implementar una función en C que lea una línea completa desde un descriptor de archivo, incluyendo un manejo eficiente de buffers y memoria.

---

## 🚀 Descripción del Proyecto

El objetivo principal de este proyecto es escribir una función llamada `get_next_line` que permita leer archivos o entradas estándar, devolviendo una línea completa en cada llamada.

Esta tarea es clave para entender conceptos fundamentales como la gestión de memoria, los buffers y la interacción con los descriptores de archivo en C.

---

## 🔧 Requisitos

### Funcionalidades Principales
- Leer una línea completa desde un descriptor de archivo.
- Manejar buffers de tamaño definido por `BUFFER_SIZE`.
- Funcionar correctamente con entradas estándar (`stdin`), archivos y sockets.
- Gestionar adecuadamente la memoria para evitar fugas.

### Restricciones
- No se permite el uso de funciones prohibidas como `malloc`, `free` (en el caso de versiones sin memoria dinámica).
- Debe manejar casos extremos como:
  - Archivos vacíos.
  - Archivos sin saltos de línea.
  - Múltiples descriptores de archivo abiertos simultáneamente.

---

## 📁 Estructura del Proyecto

```plaintext
gnl/
├── get_next_line.c       # Implementación principal de la función
├── get_next_line_utils.c # Funciones auxiliares
├── get_next_line.h       # Archivo de cabecera
├── main.c                # Archivo de prueba
├── Makefile              # Sistema de compilación
└── README.md             # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/gnl.git
   cd gnl
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta el programa de prueba con un archivo de entrada:
   ```bash
   ./gnl <archivo_de_prueba>
   ```

   **Ejemplo:**
   ```bash
   ./gnl ejemplo.txt
   ```

4. Alternativamente, prübalo con entradas desde `stdin`:
   ```bash
   echo "Hola, mundo" | ./gnl
   ```

---

## 🌟 Características

- Manejo de múltiples descriptores de archivo de manera simultánea.
- Diseño modular para facilitar la comprensión y el mantenimiento.
- Compatible con diferentes entornos, incluyendo `stdin` y archivos locales.

---

## 🧪 Testing

Realiza pruebas con diferentes archivos y configuraciones de `BUFFER_SIZE`:

```bash
gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl texto_largo.txt
```

Prueba también condiciones extremas:

- Archivos vacíos.
- Archivos sin saltos de línea.
- Tamaños de buffer pequeños (e.g., `BUFFER_SIZE=1`).

---
