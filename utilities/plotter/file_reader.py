class FileReader:
    def __init__(self, file_path):
        self.file_path = file_path

    def read_and_split(self):
        try:
            with open(self.file_path, 'r') as file:
                data = file.read()
                split_data = data.split()

                try:
                    split_data = [float(item) for item in split_data]
                except ValueError:
                    return None

                triplets = [split_data[i:i+3] for i in range(0, len(split_data), 3)]

                return triplets
        except FileNotFoundError:
            return None
