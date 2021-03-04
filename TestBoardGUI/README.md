### Bash commands for setting up the project:

```
cd TestBoardGUI
```

#### 1) Create virtual environment

```
python -m venv env
```

or, if you're on Mac (and probably Linux):

```
virtualenv venv
```

#### 2) Activate virtual environment

```
source env/Scripts/activate
```

or, if you're on Mac (and probably Linux):

```
source venv/bin/activate
```

#### 3) Install dependencies

```
pip install -r requirements.txt
```

Steps 1) and 3) are only need to be done once.

### To run the program:

```
python ui/mainwindow.py
```
Make sure the virtual environment is activated.

When finished, to deactivate the environment, simply run:

```
deactivate
```

