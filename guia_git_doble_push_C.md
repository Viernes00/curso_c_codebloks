# 🚀 Guía: Crear Nuevo Repositorio con "Doble Push"

Esta guía sirve para cualquier proyecto nuevo que quieras subir a la vez a **GitHub** y a tu servidor **Gitea**.

---

## Paso 0: Crear los repositorios en la web

Antes de tocar la consola, ve a las webs y crea un repositorio **vacío** (sin README, ni .gitignore) con el mismo nombre en ambos sitios:

1. **GitHub**: [github.com/new](https://github.com/new)
2. **Gitea**: [git.tumonstruo.es](https://git.tumonstruo.es)

---

## Paso 1: Inicializar tu carpeta local

Abre la terminal en la carpeta de tu proyecto y lanza estos comandos:

```bash
# Inicializar Git
git init

# (Opcional) Cambiar el nombre de la rama a 'main' para que coincida con Gitea
git branch -m master main

# Crear el archivo .gitignore para no subir basura (bin/, obj/...)
echo "bin/" > .gitignore
echo "obj/" >> .gitignore
```

---

## Paso 2: Primer Guardado (Commit)

```bash
git add .
git commit -m "Initial commit: Proyecto creado"
```

---

## Paso 3: Configurar el Doble Canal (La Magia)

Sustituye `TU_USUARIO` y `REPOSITORIO` por los tuyos:

```bash
# 1. Añadir Gitea como origen oficial
git remote add origin https://git.tumonstruo.es/TU_USUARIO/REPOSITORIO.git

# 2. Añadir GitHub a la lista de envíos (Push)
git remote set-url --add --push origin https://github.com/TU_USUARIO/REPOSITORIO.git

# 3. Añadir Gitea a la lista de envíos (Push)
git remote set-url --add --push origin https://git.tumonstruo.es/TU_USUARIO/REPOSITORIO.git
```

---

## Paso 4: ¡Doble Push Final! 🚀

```bash
git push -u origin main
```

A partir de ahora, cada vez que hagas `git push`, tu código volará a los dos servidores a la vez. ¡Seguridad total por duplicado! 🛡️🎩
