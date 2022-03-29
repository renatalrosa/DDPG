# Deep Deterministic Policy Gradient (DDPG) in Tensorflow and 

## Requirements
`pip3 install -r requirements.txt`

## Training
```python3
python3 main.py [-h] [--env [ENV]]
                 [--render_env [RENDER_ENV]]
                 [--train [TRAIN]]
                 [--use_noise [USE_NOISE]]
                 [--eps_greedy [EPS_GREEDY]]
                 [--warm_up [WARM_UP]]
                 [--save_weights [SAVE_WEIGHTS]]
Deep Deterministic Policy Gradient (DDPG) in Tensorflow 

optional arguments:
  -h, --help            show this help message and exit
  --env [ENV]           The OpenAI Gym environment to train on
  
  --render_env [RENDER_ENV]
                        Render the environment to be visually visible
  --train [TRAIN]       Train the network on the modified DDPG algorithm
  --use_noise [USE_NOISE]
                        OU Noise will be applied to the policy action
  --eps_greedy [EPS_GREEDY]
                        The epsilon for Epsilon-greedy in the policy's action
  --warm_up [WARM_UP]   Following recommendation from OpenAI Spinning Up, the
                        actions in the early epochs can be set random to
                        increase exploration. This warm up defines how many
                        epochs are initially set to do this.
  --save_weights [SAVE_WEIGHTS]
                        Save the weight of the network in the defined
                        checkpoint file directory.

## Network performance analysis tool is called to run the DDPG/main.py thought the multi-run.cc script of NS-3
