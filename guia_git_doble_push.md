# Explicación de Configuración Git: Doble Push

En este documento te explico qué hemos hecho exactamente en tu terminal para preparar el repositorio de tus prácticas de la UOC.

---

## Paso 1: Inicialización del Repositorio

**Comando:** `git init`

* **¿Qué hace?:** Crea una carpeta oculta llamada `.git`. A partir de ahora, Git vigilará todos los cambios que hagas en los archivos de esta carpeta para que puedas volver atrás si te equivocas.

---

## Paso 2: Creación del ".gitignore"

**Archivo:** `.gitignore`

* **¿Para qué sirve?:** Es una "lista negra". Le dice a Git qué archivos **NO** debe subir nunca a internet.
* **En tu caso:** He puesto la carpeta `datamodeler/` porque pesa mucho y ya tienes el instalador, y archivos temporales de Windows que ensucian el repositorio.

---

## Paso 3: Configuración del "Doble Push" (La Magia)

Aquí es donde hemos configurado que tu código se guarde en dos sitios a la vez (Gitea y GitHub). Hemos usado tres comandos:

1. **Añadir el destino principal:**
   `git remote add origin https://git.tumonstruo.es/viernesmaldad/UOC_basededatos.git`
   * Le decimos a Git que el sitio "oficial" (origin) es tu servidor personal.

2. **Añadir GitHub a la lista de "Push":**
   `git remote set-url --add --push origin https://github.com/Viernes00/UOC_basededatos.git`
   * Este comando le dice: "Cuando haga un envío, manda también una copia a GitHub".

3. **Confirmar Gitea en la lista de "Push":**
   `git remote set-url --add --push origin https://git.tumonstruo.es/viernesmaldad/UOC_basededatos.git`
   * Añadimos tu servidor también a la lista de envíos automáticos para que no se nos olvide.

---

## ¿Qué pasará cuando hagas el primer envío?

Como me pediste **no hacer push todavía**, tu código está a salvo solo en tu ordenador. Cuando tú decidas que estás listo, solo tendrás que escribir:

```bash
git add .
git commit -m "Mi primer commit"
git push origin master
```

**Resultado:** Automáticamente, Git enviará tu trabajo a **Gitea** y a **GitHub** en un solo movimiento. ¡Seguridad total por duplicado!
