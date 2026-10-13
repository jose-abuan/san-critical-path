import sys
import matplotlib.pyplot as plt

def plot_distribution(filenames):
    data = []
    
    # Read numbers from all provided files
    for filename in filenames:
        try:
            with open(filename, 'r') as f:
                for line in f:
                    val = line.strip()
                    if val:
                        data.append(float(val))
        except ValueError:
            print(f"Skipping invalid number in {filename}")
        except FileNotFoundError:
            print(f"Could not find file: {filename}")

    if not data:
        print("No valid data found to plot.")
        return

    # Create the distribution plot
    plt.figure(figsize=(8, 5))
    plt.hist(data, bins=50, color='skyblue', edgecolor='black', alpha=0.7)
    
    plt.title('Uniform(0,1) Distribution')
    plt.xlabel('Value')
    plt.ylabel('Frequency')
    
    # Restrict x-axis slightly past 0 and 1 for a cleaner look
    plt.xlim(-0.05, 1.05)
    plt.grid(axis='y', alpha=0.3)
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python plot_dist.py <file1.txt> [file2.txt ...]")
    else:
        plot_distribution(sys.argv[1:])