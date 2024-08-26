Pod::Spec.new do |spec|
  spec.name         = 'TDeskCore'
  spec.version      = '1.0.3'
  spec.platform     = :ios
  spec.ios.deployment_target = '9.0'
  spec.license      = { :type => 'Proprietary',
      :text => <<-LICENSE
        copyright 2017 tencent Ltd. All rights reserved.
        LICENSE
       }
  spec.homepage     = 'https://cloud.tencent.com/document/product/269/3794'
  spec.source = { :git => 'https://github.com/RoleWong/TDeskCore.git', :tag => spec.version}
  spec.documentation_url = 'https://cloud.tencent.com/document/product/269/9147'
  spec.authors      = 'tencent video cloud'
  spec.summary      = 'TUICore'
  spec.dependency 'SDWebImage'
  
  spec.requires_arc = true
#  spec.default_subspec = 'ImSDK_Plus'

  spec.source_files = '*.{h,m,mm,c}'
  spec.dependency 'TXIMSDK_Plus_iOS'
#  spec.dependency 'Masonry'
  
#  spec.subspec 'ImSDK_Plus' do |plus|
#      plus.dependency 'TXIMSDK_Plus_iOS'
#      plus.dependency 'TDeskCore/Base'
#  end
  spec.resource = ['Resources/*.bundle']
  
#  spec.subspec 'Base' do |base|
#      base.source_files = '*.{h,m,mm,c}'
#      base.resource = ['Resources/*.bundle']
#  end
  
  spec.resource_bundle = {
    "#{spec.module_name}_Privacy" => 'Resources/PrivacyInfo.xcprivacy'
  }
  
  spec.pod_target_xcconfig = {
      'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
end

