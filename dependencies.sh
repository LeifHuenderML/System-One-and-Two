conda create --name sys1and2 python=3.8
conda activate sys1and2
conda install -c anaconda cudatoolkit -y
conda install pytorch-cuda=12.1 -c pytorch -c nvidia -y
conda install pytorch torchvision torchaudio -c pytorch -c nvidia -y
pip3 install plotly pandas numpy nbformat scikit-learn 
conda install openpyxl
conda install -c conda-forge torchview
conda install -c rapidsai -c nvidia -c conda-forge cuml cudf