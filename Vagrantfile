# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure('2') do |config|
  config.vm.box = 'debian-wheezy-amd64-base'

  config.vm.provider :virtualbox do |vb|
    vb.customize [ :modifyvm, :id, '--memory', 256 ]
    vb.customize [ :modifyvm, :id, '--cpus',     1 ]
  end

  config.vm.provision :shell, path: 'cookbooks/default'
end

