
WORKFLOW='inversion'    # inversion, migration, modeling
SOLVER='specfem2d'      # specfem2d, specfem3d
SYSTEM='multithreaded'          # serial, pbs, slurm
OPTIMIZE='SRVM'         # base
PREPROCESS='base'     # base
POSTPROCESS='base'      # base

MISFIT='Waveform'
MATERIALS='Elastic'
DENSITY='Constant'


# WORKFLOW
BEGIN=1                 # first iteration
END=100                  # last iteration
NREC=500                # number of receivers
NSRC=32                 # number of sources
SAVEGRADIENT=1          # save gradient how often


# PREPROCESSING
FORMAT='su'   		# data file format
CHANNELS='xz'           # data channels
NORMALIZE=0             # normalize
BANDPASS=0              # bandpass
MUTE=0                  # mute direct arrival
FREQLO=0.               # low frequency corner
FREQHI=0.               # high frequency corner
MUTECONST=0.75          # mute constant
MUTESLOPE=1500.         # mute slope


# OPTIMIZATION
PRECOND=None
STEPMAX=5              # maximum trial steps
STEPTHRESH=0.1          # step length safeguard


# POSTPROCESSING
SMOOTH=5.               # smoothing radius
SCALE=1.                # scaling factor


# SOLVER
NT=7500                 # number of time steps
DT=9.0e-4               # time step
F0=4.0                  # dominant frequency


# SYSTEM
NTASK=NSRC              # number of tasks
NPROC=1                 # processors per task
WALLTIME=500            # walltime
NPROCMAX=38
