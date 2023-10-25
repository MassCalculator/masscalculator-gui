pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Environment setup') {
            steps {
                sh "sudo tools/installers/essentials.sh"
            }
        }
        stage('Conan Profile Detect [Temporary]') {
            steps {
                sh "conan profile detect"
            }
        }
        stage('Conan Config [Temporary]') {
            steps {
                sh "echo -e \"tools.system.package_manager:mode = install\ntools.system.package_manager:sudo = True\n\" > ~/.conan2/global.conf"
            }
        }
        stage('Local Conan Recipe Build [Temporary]') {
            steps {
                sh "conan create conan-masscalculator-core/all/ --version 0.2.0 --user masscalculator --channel stable --build missing"
            }
        }
        stage('Configure CMake') {
            parallel {
                stage('Debug') {
                    steps {
                        sh "cmake -B build/masscalculator-gui-Debug -G Ninja -DCMAKE_BUILD_TYPE=Debug"
                    }
                }
                stage('Release') {
                    steps {
                        sh "cmake -B build/masscalculator-gui-Release -G Ninja -DCMAKE_BUILD_TYPE=Release"
                    }
                }
            }
        }
        stage('Build') {
            parallel {
                stage('Debug') {
                    steps {
                        sh "cmake --build build/masscalculator-gui-Debug --config Debug"
                    }
                }
                stage('Release') {
                    steps {
                        sh "cmake --build build/masscalculator-gui-Release --config Release"
                    }
                }
            }
        }
        stage('Run') {
            parallel {
                stage('Debug') {
                    steps {
                        // @todo(jimmyhalimi): Update stages that are in progress.
                        echo 'Run stage (Debug) is in progress'
                    }
                }
                stage('Release') {
                    steps {
                        // @todo(jimmyhalimi): Update stages that are in progress.
                        echo 'Run stage (Release) is in progress'
                    }
                }
            }
        }
        stage('Package') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Package stage is in progress'
            }
        }
        stage('Deploy') {
            steps {
                // @todo(jimmyhalimi): Update stages that are in progress.
                echo 'Deploy stage is in progress'
            }
        }
    }
}
