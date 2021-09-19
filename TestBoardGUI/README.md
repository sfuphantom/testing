### Bash commands for setting up the project:

Note: Stay in testing directory.

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
pip install -r TestBoardGUI/requirements.txt
```


Steps 1) and 3) are only needed to be done once.

### To run the program:

```
python TestBoardGUI/application.py
```
Make sure the virtual environment is activated.

When finished, to deactivate the environment, simply run:

```
deactivate
```

### VSCode set-up for debugging (Optional)

Replace "program" in launch.json with the following line.
```
"program": "${workspaceFolder}/TestBoardGUI/application.py",
```

To debug in virtual environment, add "python.pythonPath" to settings.json.
```
"python.pythonPath": "env\\Scripts\\python.exe",
```


