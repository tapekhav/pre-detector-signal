import matplotlib.pyplot as plt


class Plotter:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def plot(self):
        plt.figure(figsize=(8, 6))
        plt.plot(self.x, self.y)
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.grid(True)
        plt.legend()
