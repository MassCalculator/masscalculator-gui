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
        stage('Conan Recipe Checkout [Temporary]') {
            steps {
                git branch: 'master', url: 'https://github.com/MassCalculator/conan-masscalculator-core.git'
            }
        }
        stage('Conan Profile Detect [Temporary]') {
            steps {
                sh "conan profile detect"
            }
        }
        stage('Conan Config [Temporary]') {
            steps {
                sh "conan config set tools.system.package_manager:mode=install"
            }
        }
        stage('Local Conan Recipe Build [Temporary]') {
            steps {
                dir('conan-masscalculator-core') {
                    sh "conan create all/ --version 0.1.0 --user masscalculator --channel stable --build missing"
                }
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
