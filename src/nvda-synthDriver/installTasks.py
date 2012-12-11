# Copyright (C) 2012  Olga Yakovleva <yakovleva.o.v@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys
import os
import os.path
import shutil

import config

def onInstall():
    module_dir=os.path.dirname(__file__.decode(sys.getfilesystemencoding()))
    config_dir=os.path.join(module_dir,"synthDrivers","RHVoice","config")
    config_file=os.path.join(config_dir,"RHVoice.ini")
    user_config_dir=os.path.join(config.getUserDefaultConfigPath(),"RHVoice-config")
    user_config_file=os.path.join(user_config_dir,"RHVoice.ini")
    if not os.path.isdir(user_config_dir):
        os.mkdir(user_config_dir)
    if not os.path.isfile(user_config_file):
        shutil.copy(config_file,user_config_file)