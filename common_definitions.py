"""
Common definitions of variables that can be used across files
"""

from tensorflow.keras.initializers import glorot_normal

# general parameters
CHECKPOINTS_PATH = "checkpoints/DDPG_"

# brain parameters
GAMMA = 0.909 # for the temporal difference
RHO = 0.001  # to update the target networks
KERNEL_INITIALIZER = glorot_normal()
# KERNEL_INITIALIZER = tf.random_uniform_initializer(change values)

# buffer params
UNBALANCE_P = 0.8  # newer entries are prioritized
BUFFER_UNBALANCE_GAP = 0.5

# training parameters
STD_DEV = 0.01
BATCH_SIZE = 200
BUFFER_SIZE = 1e6
TOTAL_EPISODES = 2000
CRITIC_LR = 4e-3
ACTOR_LR = 4e-4
WARM_UP = 1  # num of warm up epochs
