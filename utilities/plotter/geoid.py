import numpy as np
import matplotlib.pyplot as plt


class GeoidDrawer:
    def __init__(self, minor_axis, major_axis):
        self.minor_axis = minor_axis
        self.major_axis = major_axis

    def plot_point(self, ax, latitude, longitude, altitude):
        lat_rad = np.radians(latitude)
        lon_rad = np.radians(longitude)

        radius = np.sqrt(
            (self.major_axis ** 2 * np.cos(lat_rad) ** 2 + self.minor_axis ** 2 * np.sin(lat_rad) ** 2) /
            (np.cos(lat_rad) ** 2 + np.sin(lat_rad) ** 2)
        ) + altitude

        x = radius * np.cos(lat_rad) * np.cos(lon_rad)
        y = radius * np.cos(lat_rad) * np.sin(lon_rad)
        z = radius * np.sin(lat_rad)

        ax.scatter(x, y, z, color='red', s=50, label='Point')

    def draw(self, ax):
        u, v = np.mgrid[0:2 * np.pi:30j, 0:np.pi:20j]

        x_r = self.major_axis * np.cos(u) * np.sin(v)
        y_r = self.major_axis * np.sin(u) * np.sin(v)
        z_r = self.minor_axis * np.cos(v)

        ax.plot_surface(x_r, y_r, z_r, cmap=plt.cm.YlGnBu_r, alpha=0.5)

    def connect_points(self, ax, lat1, lon1, alt1, lat2, lon2, alt2):
        lat_rad1 = np.radians(lat1)
        lon_rad1 = np.radians(lon1)
        lat_rad2 = np.radians(lat2)
        lon_rad2 = np.radians(lon2)

        radius1 = np.sqrt(
            (self.major_axis ** 2 * np.cos(lat_rad1) ** 2 + self.minor_axis ** 2 * np.sin(lat_rad1) ** 2) /
            (np.cos(lat_rad1) ** 2 + np.sin(lat_rad1) ** 2)
        )

        x1 = radius1 * np.cos(lat_rad1) * np.cos(lon_rad1)
        y1 = radius1 * np.cos(lat_rad1) * np.sin(lon_rad1)
        z1 = radius1 * np.sin(lat_rad1) + alt1

        radius2 = np.sqrt(
            (self.major_axis ** 2 * np.cos(lat_rad2) ** 2 + self.minor_axis ** 2 * np.sin(lat_rad2) ** 2) /
            (np.cos(lat_rad2) ** 2 + np.sin(lat_rad2) ** 2)
        ) + alt2

        x2 = radius2 * np.cos(lat_rad2) * np.cos(lon_rad2)
        y2 = radius2 * np.cos(lat_rad2) * np.sin(lon_rad2)
        z2 = radius2 * np.sin(lat_rad2)

        ax.plot([x1, x2], [y1, y2], [z1, z2], linestyle='-', color='blue')
