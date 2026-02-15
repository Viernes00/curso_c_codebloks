# Configuración Git: Doble Push (Curso C)

Este documento adapta la estrategia de "Doble Push" para tu nuevo repositorio de aprendizaje de C. Con esto, cada vez que hagas un `git push`, tu código irá a la vez a tu servidor Gitea y a GitHub.

---

## 🚀 Pasos para tu Repositorio de C

### 1. Añadir el destino principal (Gitea)

Ejecuta este comando en la carpeta `codebloks`:

```bash
git remote add origin https://git.tumonstruo.es/viernesmaldad/curso_c_codebloks.git
```

### 2. Configurar el Doble Envío (GitHub)

Ahora añadimos tu GitHub a la lista de "Push" para que se envíe a los dos sitios:

```bash
git remote set-url --add --push origin https://github.com/Viernes00/curso_c_codebloks.git
```

### 3. Asegurar el envío a Gitea

Añadimos también explícitamente el de Gitea a la lista de "Push" para confirmar el doble canal:

```bash
git remote set-url --add --push origin https://git.tumonstruo.es/viernesmaldad/curso_c_codebloks.git
```

---

## ✅ Cómo subir tus avances a partir de ahora

Cada vez que termines una lección o reto y quieras guardarlo todo en internet:

1. **Prepara los archivos:** `git add .`
2. **Crea el punto de guardado:** `git commit -m "Terminada lección X"`
3. **¡Doble Push!:** `git push origin master` (o `main`)

⚠️ **Nota:** Asegúrate de haber creado los repositorios vacíos con el nombre `curso_c_codebloks` tanto en Gitea como en GitHub antes de hacer el primer push.

¡Seguridad hacker total! 🛡️💻
