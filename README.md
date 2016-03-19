# Hack The Interview Set Up
We use Heroku. Get heroku credentails from Rad.

Base Project cloned from https://github.com/heroku/heroku-django-template

## Local Machine Set up
Clone git hub repo

    git clone git@github.com:hacktheinterview/hacktheinterview.git
        
Install requirements.txt

    sudo pip install -r requirements.txt
    
Install postgresSQL from http://postgresapp.com/

    psql

Create database and user

    CREATE DATABASE ht;
    CREATE USER hack_user WITH PASSWORD 'hack_pass';
    GRANT ALL PRIVILEGES ON DATABASE ht TO hack_user;
            
Set default encoding to UTF-8 and timezone to UTC which Django expects.

    ALTER ROLE hack_user SET client_encoding TO 'utf8';
    ALTER ROLE hack_user SET default_transaction_isolation TO 'read committed';
    ALTER ROLE hack_user SET timezone TO 'UTC';

Go to project root and run the following to run the web-server locally

    heroku local -p 5767
        
## Github workflow

    $ git checkout -b feature-branch
    $ touch new-file.txt
    $ git commit -a -m 'Added new-file.txt'
    $ git push origin feature-branch
    
    # Go to https://github.com/hacktheinterview/hacktheinterview to create a Pull Request.
    # Circle CI runs your code 
    # Merge the code into master
    
## Deployment Example to Heroku

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
