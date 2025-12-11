import sqlite3
import os


class BaseConstructor:
    def __init__(self,baseName):
        self.baseName = baseName
        connection = sqlite3.connect(f'{baseName}.db')
        cursor = connection.cursor()
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS Files (
        id INTEGER PRIMARY KEY,
        fileName TEXT UNIQUE ON CONFLICT IGNORE,
        size INTEGER

        )
        ''')

        connection.commit()
        connection.close()

    def print_base(self):
        connection = sqlite3.connect(f'{self.baseName}.db')
        cursor = connection.cursor()
        cursor.execute("SELECT fileName, size FROM Files ORDER BY -size")
        users = cursor.fetchall()
        connection.close()
        return users

    def insert(self, fileName, size):
        connection = sqlite3.connect(f'{self.baseName}.db')
        cursor = connection.cursor()
        cursor.execute(f"INSERT INTO Files (fileName, size) VALUES ('{fileName}', {size})")
        connection.commit()
        connection.close()

    def update (self, fileName, s):
        connection = sqlite3.connect(f'{self.baseName}.db')
        cursor = connection.cursor()
        cursor.execute(f"SELECT fileName, size FROM Users WHERE fileName = '{fileName}'")
        score = cursor.fetchall()
        if s>int(score[0][1]):
            cursor.execute('UPDATE Users SET score = ? WHERE nickname = ?', (s, fileName))
        connection.commit()
        connection.close()

    def delete(self, fileName):
        connection = sqlite3.connect(f'{self.baseName}.db')
        cursor = connection.cursor()
        cursor.execute(f"DELETE FROM Files WHERE fileName = '{fileName}'")
        connection.commit()
        connection.close()

class manager(BaseConstructor):
    def __init__(self):
        self.base = BaseConstructor("files")
        self.FilesInDB = self.base.print_base()
        self.cDirectory = "E:\\git repoes\\projects\\Python\\Копировальщик\\test2"
        self.tDirectory = "E:\\git repoes\\projects\\Python\\Копировальщик\\test1"
        self.tFiles = self.getFiles(self.cDirectory)
        
        

    def getFiles(self, path):
        fun = lambda x : os.path.isfile(os.path.join(path,x))
        files_list = filter(fun, os.listdir(path))
        size_of_file = [
        (f,os.stat(os.path.join(path, f)).st_size)
        for f in files_list
        ]
        return size_of_file

if __name__ == "__main__":
    fileManager = manager()