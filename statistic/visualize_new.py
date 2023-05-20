import numpy as np
import matplotlib.pyplot as plt

COLORS = ["b", "g", "r", "c", "m", "y"]

class Structure_data:
    def __init__(self, table):
        self.table = table
        self.structured_data = self.strucure()

    def strucure(self):
        # data = [{}] * len(self.table)
        data = [{} for _ in range(len(self.table))]
        for index, column in enumerate(self.table):
            for el in column:
                if el in data[index]:
                    data[index][el] += 1 + index

                else:
                    data[index][el] = 1

        return data

    def get_only_nums(self):
        ...

    def get_xy(self, id):
        x, y = [], []
        for key in self.structured_data[id]:
            x.append(key)
            y.append(self.structured_data[id][key])

        return x, y

    def draw(self):
        _, ax = plt.subplots(nrows=2, ncols=3)
        for i in range(len(self.structured_data)):
            data = self.get_xy(i)

            x_data = np.array(data[0])
            y_data = np.array(data[1])

            ax[0][0].scatter(x_data, y_data, s = 10, color = COLORS[i], alpha = 0.75)
            ax[0][0].legend([el for el in x_data])
            ax[0][1].plot(x_data, y_data, color = COLORS[i], alpha = 0.75)
            ax[0][1].legend([el for el in x_data])
            ax[0][2].hist(y_data, color = COLORS[i], alpha = 0.75)
            ax[0][2].legend([el for el in x_data])
            ax[1][0].boxplot(y_data, patch_artist = True)
            ax[1][0].legend([el for el in x_data])
            ax[1][1].bar(x_data, y_data, color = COLORS[i], alpha = 0.75)
            ax[1][1].legend([el for el in x_data])

            for nrows in range(2):
                for ncols in range(3):
                    ax[nrows][ncols].set_xlabel("key")
                    ax[nrows][ncols].set_ylabel("count")
        plt.show()
