#*----------------------------------------------------------------------------*\
#  Cryptographic protocol types and associated factory
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/

#*----------------------------------------------------------------------------*\
#  Ruby-style enum for crypto types
#*----------------------------------------------------------------------------*/
class CryptoTypes
   PVP = 1
   ID1 = 2
   RSA = 3
   RDX = 4
end

#*----------------------------------------------------------------------------*\
#  CryptoTypePVP
#*----------------------------------------------------------------------------*/
class CryptoTypePVP
   def encrypt_video
      "PVP"
   end
end

#*----------------------------------------------------------------------------*\
#  CryptoTypeID1
#*----------------------------------------------------------------------------*/
class CryptoTypeID1
   def encrypt_video
      "ID1"
   end
end

#*----------------------------------------------------------------------------*\
#  CryptoTypeRSA
#*----------------------------------------------------------------------------*/
class CryptoTypeRSA
   def encrypt_video
      "RSA"
   end
end

#*----------------------------------------------------------------------------*\
#  CryptoTypeRDX
#*----------------------------------------------------------------------------*/
class CryptoTypeRDX
   def encrypt_video
      "RDX"
   end
end

#*----------------------------------------------------------------------------*\
#  CryptoTypeFactory
#*----------------------------------------------------------------------------*/
class CryptoTypeFactory
   class << self
      def get_crypto_type(crypto_type)
         case crypto_type
         when CryptoTypes::PVP
            CryptoTypePVP.new
         when CryptoTypes::ID1
            CryptoTypeID1.new
         when CryptoTypes::RSA
            CryptoTypeRSA.new
         when CryptoTypes::RDX
            CryptoTypeRDX.new
         else
            nil
         end
      end
   end
end
