# Hack The Interview Set Up
Base Project cloned from https://github.com/heroku/heroku-django-template

## Local Machine Set up

$ git clone git@github.com:hacktheinterview/hacktheinterview.git

## How to Use

To use this project, follow these steps:

1. Create your working environment.
2. Install Django (`$ pip install django`)
3. Create a new project using this template

## Creating Your Project

Using this template to create a new Django app is easy::

    $ django-admin.py startproject --template=https://github.com/heroku/heroku-django-template/archive/master.zip --name=Procfile helloworld

You can replace ``helloworld`` with your desired project name.

## Deployment to Heroku

    $ touch file.txt
    $ git add -A
    $ git commit -m "Commit"

    $ heroku create
    $ git push heroku master

    Always run migrate
    $ heroku run python manage.py migrate 


## Further Reading

- [Gunicorn](https://warehouse.python.org/project/gunicorn/)
- [WhiteNoise](https://warehouse.python.org/project/whitenoise/)
- [dj-database-url](https://warehouse.python.org/project/dj-database-url/)
