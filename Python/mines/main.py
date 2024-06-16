from random import randint


class Game:
    def __init__(self):
        self.pole = []
        self.square = 8
        mines = 20
        for i in range(self.square):
            x = []
            for t in range(self.square):
                if mines > 0:
                    mine = randint(0, 1)
                else:
                    mine = "0"
                if mine == 1:
                    mines -= 1
                    mine = "m"
                else:
                    mine = '0'
                x.append(mine)
            self.pole.append(x)
        self.define()

    def define(self):
        for y in range(len(self.pole)):
            row = self.pole[y]
            for x in range(len(row)):
                if row[x] == "m":
                    if y == 0:
                        if x == 0:
                            if row[x+1] != "m":
                                self.pole[y][x+1] = str(int(self.pole[y][x+1])+1)
                            if self.pole[y+1][x] != "m":
                                self.pole[y+1][x] = str(int(self.pole[y+1][x])+1)
                            if self.pole[y+1][x+1] != "m":
                                self.pole[y+1][x+1] = str(int(self.pole[y+1][x+1])+1)
                        elif x == self.square - 1:
                            if row[x-1] != "m":
                                self.pole[y][x-1] = str(int(self.pole[y][x-1])+1)
                            if self.pole[y+1][x] != "m":
                                self.pole[y+1][x] = str(int(self.pole[y+1][x])+1)
                            if self.pole[y+1][x-1] != "m":
                                self.pole[y+1][x-1] = str(int(self.pole[y+1][x-1])+1)
                        else:
                            if row[x-1] != "m":
                                self.pole[y][x-1] = str(int(self.pole[y][x-1])+1)
                            if row[x+1] != "m":
                                self.pole[y][x+1] = str(int(self.pole[y][x+1])+1)
                            if self.pole[y+1][x] != "m":
                                self.pole[y+1][x] = str(int(self.pole[y+1][x])+1)
                            if self.pole[y+1][x-1] != "m":
                                self.pole[y+1][x-1] = str(int(self.pole[y+1][x-1])+1)
                            if self.pole[y+1][x+1] != "m":
                                self.pole[y+1][x+1] = str(int(self.pole[y+1][x+1])+1)
                    elif y == self.square - 1:
                        if x == 0:
                            if row[x+1] != "m":
                                self.pole[y][x+1] = str(int(self.pole[y][x+1])+1)
                            if self.pole[y-1][x] != "m":
                                self.pole[y-1][x] = str(int(self.pole[y-1][x])+1)
                            if self.pole[y-1][x+1] != "m":
                                self.pole[y-1][x+1] = str(int(self.pole[y-1][x+1])+1)
                        elif x == self.square - 1:
                            if row[x-1] != "m":
                                self.pole[y][x-1] = str(int(self.pole[y][x-1])+1)
                            if self.pole[y-1][x] != "m":
                                self.pole[y-1][x] = str(int(self.pole[y-1][x])+1)
                            if self.pole[y-1][x-1] != "m":
                                self.pole[y-1][x-1] = str(int(self.pole[y-1][x-1])+1)
                        else:
                            if row[x-1] != "m":
                                self.pole[y][x-1] = str(int(self.pole[y][x-1])+1)
                            if row[x+1] != "m":
                                self.pole[y][x+1] = str(int(self.pole[y][x+1])+1)
                            if self.pole[y-1][x] != "m":
                                self.pole[y-1][x] = str(int(self.pole[y-1][x])+1)
                            if self.pole[y-1][x-1] != "m":
                                self.pole[y-1][x-1] = str(int(self.pole[y-1][x-1])+1)
                            if self.pole[y-1][x+1] != "m":
                                self.pole[y-1][x+1] = str(int(self.pole[y-1][x+1])+1)
                    else:
                        if x == 0:
                            if row[x + 1] != "m":
                                self.pole[y][x + 1] = str(int(self.pole[y][x + 1]) + 1)
                            if self.pole[y - 1][x] != "m":
                                self.pole[y - 1][x] = str(int(self.pole[y - 1][x]) + 1)
                            if self.pole[y - 1][x + 1] != "m":
                                self.pole[y - 1][x + 1] = str(int(self.pole[y - 1][x + 1]) + 1)
                            if self.pole[y + 1][x] != "m":
                                self.pole[y + 1][x] = str(int(self.pole[y + 1][x]) + 1)
                            if self.pole[y + 1][x + 1] != "m":
                                self.pole[y + 1][x + 1] = str(int(self.pole[y + 1][x + 1]) + 1)
                        elif x == self.square - 1:
                            if row[x - 1] != "m":
                                self.pole[y][x - 1] = str(int(self.pole[y][x - 1]) + 1)
                            if self.pole[y - 1][x] != "m":
                                self.pole[y - 1][x] = str(int(self.pole[y - 1][x]) + 1)
                            if self.pole[y - 1][x - 1] != "m":
                                self.pole[y - 1][x - 1] = str(int(self.pole[y - 1][x - 1]) + 1)
                            if self.pole[y + 1][x] != "m":
                                self.pole[y + 1][x] = str(int(self.pole[y + 1][x]) + 1)
                            if self.pole[y + 1][x - 1] != "m":
                                self.pole[y + 1][x - 1] = str(int(self.pole[y + 1][x - 1]) + 1)
                        else:
                            if row[x - 1] != "m":
                                self.pole[y][x - 1] = str(int(self.pole[y][x - 1]) + 1)
                            if row[x + 1] != "m":
                                self.pole[y][x + 1] = str(int(self.pole[y][x + 1]) + 1)
                            if self.pole[y - 1][x] != "m":
                                self.pole[y - 1][x] = str(int(self.pole[y - 1][x]) + 1)
                            if self.pole[y - 1][x - 1] != "m":
                                self.pole[y - 1][x - 1] = str(int(self.pole[y - 1][x - 1]) + 1)
                            if self.pole[y - 1][x + 1] != "m":
                                self.pole[y - 1][x + 1] = str(int(self.pole[y - 1][x + 1]) + 1)
                            if self.pole[y + 1][x] != "m":
                                self.pole[y + 1][x] = str(int(self.pole[y + 1][x]) + 1)
                            if self.pole[y + 1][x - 1] != "m":
                                self.pole[y + 1][x - 1] = str(int(self.pole[y + 1][x - 1]) + 1)
                            if self.pole[y + 1][x + 1] != "m":
                                self.pole[y + 1][x + 1] = str(int(self.pole[y + 1][x + 1]) + 1)




if __name__ == "__main__":
    app = Game()
    for p in app.pole:
        print(p)
