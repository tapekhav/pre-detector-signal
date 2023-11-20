import numpy as np

from geoid import *
from plotter import Plotter
from file_reader import FileReader

MAJOR_AXIS = 6378137
MINOR_AXIS = 6356752


class Main:
    def __init__(self):
        file_reader = FileReader('plotters/meters.txt')
        self.arr = file_reader.read_and_split()
        self.x = self.get_coordinate(0)
        self.y = self.get_coordinate(1)
        self.z = self.get_coordinate(2)

    def get_coordinate(self, axis):
        return [self.arr[i][axis] for i in range(len(self.arr))]

    def draw_projection_plots(self):
        time = np.linspace(0.0, 100000.0, 200000)

        x_plotter = Plotter(time, self.x)
        x_plotter.plot()

        y_plotter = Plotter(time, self.y)
        y_plotter.plot()

        z_plotter = Plotter(time, self.z)
        z_plotter.plot()

    def draw_geoid(self):
        file_reader = FileReader('plotters/coordinates.txt')
        self.arr = file_reader.read_and_split()

        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        geoidDr = GeoidDrawer(MINOR_AXIS, MAJOR_AXIS)

        geoidDr.draw(ax)

        l = len(self.arr) - 1

        geoidDr.plot_point(ax, self.arr[0][0], self.arr[0][1], self.arr[0][2])
        geoidDr.plot_point(ax, self.arr[l][0], self.arr[l][1], self.arr[l][2])

        geoidDr.connect_points(ax, self.arr[0][0], self.arr[0][1], self.arr[0][2],
                               self.arr[l][0], self.arr[l][1], self.arr[l][2])

        ax.set_xlim(-MAJOR_AXIS, MAJOR_AXIS)
        ax.set_ylim(-MAJOR_AXIS, MAJOR_AXIS)
        ax.set_zlim(-MINOR_AXIS, MINOR_AXIS)


def main():
    main_object = Main()

    main_object.draw_projection_plots()
    main_object.draw_geoid()

    plt.show()


if __name__ == '__main__':
    main()
